
/* Copyright (C) 2014 Kristian Lauszus, TKJ Electronics. All rights reserved.

 This software may be distributed and modified under the terms of the GNU
 General Public License version 2 (GPL2) as published by the Free Software
 Foundation and appearing in the file GPL2.TXT included in the packaging of
 this file. Please note that GPL2 Section 2[b] requires that all works based
 on this software must also be made publicly available under the terms of
 the GPL2 ("Copyleft").

 Contact information
 -------------------

 Kristian Lauszus, TKJ Electronics
 Web      :  http://www.tkjelectronics.com
 e-mail   :  kristianl@tkjelectronics.com
 */



#include <TinyGPS.h>
#include <Wire.h> //I2C Arduino Library
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>
#include "Kalman.h" 

//#define address 0x1E //0011110b, I2C 7bit address of HMC5883

#define dir485 6
#define pin_led 13
#define pin_led_o 8
#define pin_led_r 9
#define pin_led_w 10
#define buttonPin  7

////////////////////////////////////////////////////////////////////////////////
#define latminPoint_0 468
#define latmaxPoint_0 470
#define lonminPoint_0 439
#define lonmaxPoint_0 442
#define yowPoint_0  30
 
#define latminPoint_1  458
#define latmaxPoint_1  462//478
#define lonminPoint_1  439
#define lonmaxPoint_1  442
#define yowPoint_1     185

#define latminPoint_2 468
#define latmaxPoint_2 473//473
#define lonminPoint_2 406
#define lonmaxPoint_2 410
#define yowPoint_2 148

#define latminPoint_3 465
#define latmaxPoint_3 467
#define lonminPoint_3 400
#define lonmaxPoint_3 402
#define yowPoint_3 131

#define latminPoint_4 449
#define latmaxPoint_4 451
#define lonminPoint_4 492
#define lonmaxPoint_4 494
#define yowPoint_4 46

#define latminPoint_5 428
#define latmaxPoint_5 446
#define lonminPoint_5 399
#define lonmaxPoint_5 400
#define yowPoint_5 23

#define latminPoint_6 407
#define latmaxPoint_6 415
#define lonminPoint_6 397
#define lonmaxPoint_6 400
#define yowPoint_6 25

#define latminPoint_7 424
#define latmaxPoint_7 428
#define lonminPoint_7 447
#define lonmaxPoint_7 450
#define yowPoint_7 319

#define latminPoint_8 430
#define latmaxPoint_8 431
#define lonminPoint_8 447
#define lonmaxPoint_8 410
#define yowPoint_8 257

#define latminPoint_9 448
#define latmaxPoint_9 451
#define lonminPoint_9 447
#define lonmaxPoint_9 453
#define yowPoint_9 247

#define latminPoint_10 456  //455
#define latmaxPoint_10 457
#define lonminPoint_10 446  //445
#define lonmaxPoint_10 450
#define yowPoint_10 207

//
////////////////////////////////////////////////////////////////////////////////

boolean parameters_UpdateComplete =false;
/* Assign a unique ID to this sensor at the same time */
Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////


// Source: https://github.com/TKJElectronics/KalmanFilter

#define RESTRICT_PITCH // Comment out to restrict roll to ±90deg instead - please read: http://www.freescale.com/files/sensors/doc/app_note/AN3461.pdf

Kalman kalmanX, kalmanY, kalmanZ; // Create the Kalman instances

const uint8_t MPU6050 = 0x68; // If AD0 is logic low on the PCB the address is 0x68, otherwise set this to 0x69
const uint8_t HMC5883L_ = 0x1E; // Address of magnetometer
const uint16_t I2C_TIMEOUT = 1000; // Used to check for errors in I2C communication

/* IMU Data */
double accX, accY, accZ;
double gyroX, gyroY, gyroZ;
double magX, magY, magZ;
int16_t tempRaw;

double roll, pitch, yaw; // Roll and pitch are calculated using the accelerometer while yaw is calculated using the magnetometer

double gyroXangle, gyroYangle, gyroZangle; // Angle calculate using the gyro only
double compAngleX, compAngleY, compAngleZ; // Calculated angle using a complementary filter
double kalAngleX, kalAngleY, kalAngleZ; // Calculated angle using a Kalman filter

uint32_t timer;
uint8_t i2cData[14]; // Buffer for I2C data

#define MAG0MAX 603
#define MAG0MIN -578

#define MAG1MAX 542
#define MAG1MIN -701

#define MAG2MAX 547
#define MAG2MIN -556

float magOffset[3] = { (MAG0MAX + MAG0MIN) / 2, (MAG1MAX + MAG1MIN) / 2, (MAG2MAX + MAG2MIN) / 2 };
double magGain[3];

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

byte ID=0;
byte dirtL = 0;
byte dirtR = 0;
byte veloL = 0;
byte veloR = 0;

byte point = 0;
byte lastpoint=0;
byte nextpoint =0; 
int  yow_point_target[10];

int sensor1,sensor2,sensor3, inches;
int distanceBegin = 10;
///////////////////////////////////////////////////////////////////////
int KP = 2000; //position multiplier (gain)100
int KI = 10; // Intergral multiplier (gain)1
int KD = 5000; // derivative multiplier (gain)

int lastError = 0;
int sumError = 0;
//Integral term min/max (random value and not yet tested/verified)
int iMax = 100;
int iMin = 0;

long previousTarget = 0;
long previousMillis = 0;        // will store last time LED was updated
long interval = 10;           // interval at which to blink (milliseconds)

///////////////////////////////////////////////////////////////

//////////////////////////Compass/////////////////////////////////////////////
int KP_C = 200; //position multiplier (gain)100
int KI_C = 1; // Intergral multiplier (gain)1
int KD_C = 1000; // derivative multiplier (gain)

int lastError_C = 0;
int sumError_C = 0;
//Integral term min/max (random value and not yet tested/verified)
int iMax_C = 100;
int iMin_C = 0;

int headingDegrees_C =0;
int lon_G=0;
int lat_G=0;
int yaw_imu =0;
int yaw_imu_B =0;
unsigned long lastmillis = 0; 
unsigned long lastmillis2 = 0; 
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
 
  const int numReadings = 5;
  int readings[numReadings];      // the readings from the analog input
  int index = 0;                  // the index of the current reading
  int total = 0;                  // the running total
  int average = 0;                // the average
 ///////////////////////////////////////////////////////////////////////




TinyGPS gps;
void gpsdump(TinyGPS &gps);
void printFloat(double f, int digits = 2);
static void print_int(unsigned long val, unsigned long invalid, int len);


int buttonState = 0;
boolean time_Pid = true;

void setup(){
  
  initial_pin();
  
  //Initialize Serial and I2C communications
  Serial.begin(115200);   ////////Debug
  Serial1.begin(115200); //////////////485
  Serial2.begin(9600); //////////////GPS
  Serial3.begin(115200); /////////////WIFI
  Wire.begin();
  
 /* 
  //Put the HMC5883 IC into the correct operating mode
  Wire.beginTransmission(address); //open communication with HMC5883
  Wire.write(0x02); //select mode register
  Wire.write(0x00); //continuous measurement mode
  Wire.endTransmission();
 */ 
  digitalWrite(dir485,HIGH);
 // Sendto_motor(1,1,100);
  
  Serial.print("start");
  digitalWrite(pin_led_o,HIGH);
  digitalWrite(pin_led_r,HIGH);
  digitalWrite(pin_led_w,HIGH);
 // initialHMC5883();
  setup_imu();
  update_imu();
  yaw_imu_B=yaw_imu;
  digitalWrite(pin_led_o,LOW);
  digitalWrite(pin_led_r,LOW);
  digitalWrite(pin_led_w,LOW);
  lastmillis =0; // Uptade lasmillis
  lastmillis2 =0; // Uptade lasmillis
}

void loop(){
       
       buttonState = digitalRead(buttonPin);
       ///;
//        if (((unsigned long)(millis() - lastmillis) >= 10)&&(time_Pid)){ //Uptade every one second, this will be equal to reading frecuency (Hz).
//                            
//                           // Serial.println("######################################################");
//                           // readGps();
//                            do_pidCompass(yowPoint_0, 500, 2, 500);
//                            lastmillis = millis(); // Uptade lasmillis
//                          }  

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
     /*   if ((unsigned long)(millis() - lastmillis2) >= 500){ //Uptade every one second, this will be equal to reading frecuency (1Hz).
                            
                          //  Serial.println("**************************************************************************************************************************************");
                            readGps();
                       //    do_pidCompass(yowPoint_0, 3500, 100, 10);
                            lastmillis2 = millis(); // Uptade lasmillis
                          } 
                   */       
                          
////////////////////////////////////////////////////////////////////////////////////////////////////////                          
                          
       if (buttonState == HIGH)
        {    
             // Serial.println("CalibrateIMU");
              robot_S();
              time_Pid =false;
              digitalWrite(pin_led_w,HIGH);     
              readGps();
             // Serial.println();
              update_imu();
              delay(50);
              digitalWrite(pin_led_w,LOW); 
                
        }
        else {
                      
                       /// runWaypoint();
                        if (Serial.available() > 0) {
                                    
                                      // read the incoming byte:
                                      char inChar = Serial.read();
                                         serialCheck(inChar);
                                     
                                   }   
                                 else{
                                   
                                    runWaypoint();
                               
                                    } 
                          
                          
                          /*
                         time_Pid =true;
                         //readGps();
                        // update_imu();
                         runWaypoint();
                         readDistance();
                         do_pidposition(12);
                        
                       if(sensor2>20){
                           robot_L(130,130);
                           delay(20);
                            robot_S();
                             delay(50);
                            robot_F(170,170);
                             delay(100);
                         }/*.........................................................................................................................\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\.............................
//                         else if(sensor3<12){
//                           robot_L(130,130);
//                           delay(300);
//                            robot_S();
//                         }
//                         else{
//                         
//                         }*/
                     /*   // Serial.print(lat_G); Serial.println(lon_G);
                         if (((lat_G>=461)&&(lat_G<=473))&&((lon_G>=418)&&(lon_G<=423)))
                         {
                            robot_F(130,130);
                            delay(100);
                            robot_S();
                            delay(1000);
                            robot_L(130,130);
                            delay(100);
                            robot_S();
                            delay(500);
                            Serial.println("RUN######################################################");
                            nextpoint =2;
                            digitalWrite(pin_led_r,HIGH);
                            digitalWrite(pin_led_o,LOW);
                            digitalWrite(pin_led_w,HIGH);
                         }
                        
                        
                        else {       //Serial.println("RUN");
                                   //do_pidCompass(470, 200, 1, 1000);

                                   // runWaypoint();
                                
                                  //   recive_command();
                                 //   digitalWrite(pin_led_r,LOW);
                                    digitalWrite(pin_led_o,HIGH);
                                    digitalWrite(pin_led_w,LOW);
                                    do_pidCompass(yowPoint_0, 3000, 100, 10);
                                    
                                  if (Serial.available() > 0) {
                                    
                                      // read the incoming byte:
                                      char inChar = Serial.read();
                                         serialCheck(inChar);
                                     
                                   }   
                                 else{
                                   
                                  //  runWaypoint();
                               
                                    } 
                        }
                     */
        }
        
    
}

void Sendto_motor(byte id, byte dir, byte vlo)
{
        digitalWrite(dir485,HIGH);
        byte inStruction =6;
        int chkSum = 0;
        Serial1.write(255);
        Serial1.write(255);
        Serial1.write(id);
        Serial1.write(inStruction);
        Serial1.write(2);
        Serial1.write(dir);
        Serial1.write(vlo);
        Serial1.write(0);
        Serial1.write(0);
        chkSum =id+inStruction+2+dir+vlo+0+0;
        chkSum =chkSum%255;
        chkSum =255-chkSum;
        Serial1.write(chkSum);
  
   
}

void robot_F(byte pwm1,byte pwm2)
{
  Sendto_motor(1,0,pwm1);
  Sendto_motor(2,1,pwm2);
}

void robot_B(byte pwm1,byte pwm2)
{
  Sendto_motor(1,1,pwm1);
  Sendto_motor(2,0,pwm2);
}

void robot_L(byte pwm1,byte pwm2)
{
  Sendto_motor(1,1,pwm1);
  Sendto_motor(2,1,pwm2);
}

void robot_R(byte pwm1,byte pwm2)
{
  Sendto_motor(1,0,pwm1);
  Sendto_motor(2,0,pwm2);
}
void robot_S()
{
  Sendto_motor(1,3,0);
  Sendto_motor(2,3,0);
}



//void serialEvent() {
//  while (Serial.available()) {
//   recive_command();
//   parameters_UpdateComplete =true;
//  }
//}


void readGps()
{

 bool newdata = false;
  unsigned long start = millis();

  // Every 5 seconds we print an update
  while (millis() - start < 100)
 {
    if (Serial2.available()) {
      char c = Serial2.read();
      // Serial.print(c);  // uncomment to see raw GPS data
      if (gps.encode(c)) {
        newdata = true;
         break;  // uncomment to print new data immediately!
      }
    }
  }
  
  if (newdata) {
    //Serial.println("Acquired Data");
    //Serial.println("-------------");
    gpsdump(gps);
    //Serial.println("-------------");
    //Serial.println();
  }
  

}


void serialCheck( char inChar)
{
     
        
          if(inChar == 'q') {
              Serial.flush();
              robot_S();
            //  readGps();
              update_imu();
             // gatHMC5883();
              digitalWrite(pin_led_o,HIGH);
              digitalWrite(pin_led_r,HIGH);
              delay(5);
              
            //  Serial.println("q");
          }
         else if(inChar == 'c') {
      
              //gatHMC5883();
              update_imu();
              digitalWrite(pin_led_o,HIGH);
             //   Serial.println("c");
          }
         else if(inChar == 'g') {
           
             digitalWrite(pin_led_r,HIGH);
              readGps();
            //  Serial.println(" ");
            //  Serial.println("g");
              
          }
         else if(inChar == 'e') {
              Serial.println("e");
              do_pidposition(distanceBegin);
            }
         else if(inChar == 'W') {
             // Serial.println("W");
              robot_F(100,100);
            }
        else if(inChar == 'S') {
           // Serial.println("S");
            robot_B(100,100);
          }
       else if(inChar == 'A') {
            //Serial.println("A");
            robot_L(100,100);
          }
       else if(inChar == 'D') {
           // Serial.println("D");
            robot_R(100,100);
          }
       else if(inChar == 'B') {
           // Serial.println("D");
             robot_S();
          }
      else {
          //recive_command();
     
          }
      
  


}


void runWaypoint(){

     if (nextpoint==0)
     {
       nextpoint =1;
          }  
    // robot_S();
     digitalWrite(pin_led_o,HIGH);
     
      waypoint(nextpoint);
//     readGps();
////     update_imu();
//    if (millis() - lastmillis >= 100){ //Uptade every one second, this will be equal to reading frecuency (Hz).
//       do_pidCompass((-168)+360, 400, 1, 1000);
//      lastmillis = millis(); // Uptade lasmillis
//    }
//  // robot_F(100,100);
//  // delay(50);
//     digitalWrite(pin_led_o,LOW);
     
     
     
}

void setup_imu()
{
 TWBR = ((F_CPU / 400000L) - 16) / 2; // Set I2C frequency to 400kHz

  i2cData[0] = 7; // Set the sample rate to 1000Hz - 8kHz/(7+1) = 1000Hz
  i2cData[1] = 0x00; // Disable FSYNC and set 260 Hz Acc filtering, 256 Hz Gyro filtering, 8 KHz sampling
  i2cData[2] = 0x00; // Set Gyro Full Scale Range to ±250deg/s
  i2cData[3] = 0x00; // Set Accelerometer Full Scale Range to ±2g
  while (i2cWrite(MPU6050, 0x19, i2cData, 4, false)); // Write to all four registers at once
  while (i2cWrite(MPU6050, 0x6B, 0x01, true)); // PLL with X axis gyroscope reference and disable sleep mode

  while (i2cRead(MPU6050, 0x75, i2cData, 1));
  if (i2cData[0] != 0x68) { // Read "WHO_AM_I" register
    Serial.print(F("Error reading sensor"));
    while (1);
  }

  while (i2cWrite(HMC5883L_, 0x02, 0x00, true)); // Configure device for continuous mode
  calibrateMag();

  delay(100); // Wait for sensors to stabilize

  /* Set Kalman and gyro starting angle */
  updateMPU6050();
  updateHMC5883L();
  updatePitchRoll();
  updateYaw();

  kalmanX.setAngle(roll); // First set roll starting angle
  gyroXangle = roll;
  compAngleX = roll;

  kalmanY.setAngle(pitch); // Then pitch
  gyroYangle = pitch;
  compAngleY = pitch;

  kalmanZ.setAngle(yaw); // And finally yaw
  gyroZangle = yaw;
  compAngleZ = yaw;

  timer = micros(); // Initialize the timer

}
//void manual()
//{
//
//
//
//
//
//}


long ulCounter = 0;
int inByte = 0;
///////////Dynamixel variable////////////////////
#define READ 2
#define WRITE 3
int chkSum = 0;
unsigned char inStruction = 0;
unsigned char lengTh = 0;
unsigned char paraMeters[4];
char stReadComplete = 0;

////////////////////////////////////////////





void recive_command()
{
 //  digitalWrite(dir485, LOW);
  //test_run();
    digitalWrite(pin_led_w, HIGH);
  stReadComplete = false;
   if(get_serial_chk_state(255))
   {
    // Serial.print("FirstStartComp ");
     wait_serial_timeout_check();
     if(get_serial_chk_state(255))
     {
      // Serial.print("StartComp ");
       
       wait_serial_timeout_check();
       if(get_serial_chk_state(ID))
       {
         //digitalWrite(dir485, HIGH);
         // Serial.print("IDComp ");
         //digitalWrite(dir485, LOW);
          wait_serial_timeout_check();
          lengTh = Serial.read();       //get lenght
        //  Serial.println("lengTh");
          wait_serial_timeout_check(); 
          inStruction = Serial.read();  //get inStruction
         // Serial.println("inStruction");
          chkSum = (ID+lengTh+inStruction);
          if((lengTh>0)&&(lengTh<20))
          {
            for(char i = 0;i<lengTh-2;i++)
            {
              wait_serial_timeout_check(); 
              paraMeters[i] = Serial.read();
              chkSum =  chkSum+paraMeters[i];
             //Serial.print("p = ");
            // Serial.print(paraMeters[i],DEC);
            }
          }
          chkSum = chkSum%255;
          chkSum = 255-chkSum;
          wait_serial_timeout_check(); 
          //Serial.println("chkSum");
          if(get_serial_chk_state(chkSum))
          {
             //  Serial.print("ChkComp ");
             
              stReadComplete = true;
              digitalWrite(pin_led_w, LOW);
            //  digitalWrite(dir485, HIGH);
              //Serial.println(ID);
              //parameters_update();
              
              parameters_update();
              Serial.print("{");
              ///
              
              //digitalWrite(4,LOW);
              //delay(1000);
              //digitalWrite(4,HIGH);  
               //Serial.println("GetComp");
          }       
       }
       
     }
     //Serial.println(" ");
   }
}




char get_serial_chk_state(int target)
{
       if (Serial.available() > 0)
        {
          
          inByte = Serial.read();
          //Serial.println(inByte);
          if(inByte == target)
          {
            return 1;
          }
          else 
          {
              return 0;
            //Serial.flush();
          }
        }
       else 
       {
         return 0; 
       }
}


void wait_serial_timeout_check()
{
  ulCounter = 0;
  while(Serial.available() == 0)
      {
        ulCounter++;
        if(ulCounter>1400)//14000
        {
          //Serial.println(ulCounter);
          //loop();
          break;
        }
        //Serial.println('w');
      }
}



void parameters_update()
{
  unsigned char pos_H = 0;
  unsigned char pos_L = 0;
  
  //////// old///////
//  dirt = paraMeters[0];
//  velo = paraMeters[1];
//  pos_H = paraMeters[2];
//  pos_L = paraMeters[3];
//////////////////////////  
//  dirt = paraMeters[0];
//  pos_H = paraMeters[1];
//  pos_L = paraMeters[2];
//  gif = paraMeters[3];
   dirtL = paraMeters[0];
   dirtR = paraMeters[1];
   veloL = paraMeters[2];
   veloR = paraMeters[3];
  
//  pos = pos_H;
//  pos = pos << 8;
//  pos += pos_L;
 /// pos=(pos*1100)/360;
// 
// if(dirt==1)
// {
//    pos = pos*-1;
// }
// 
}



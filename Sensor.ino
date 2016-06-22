void displaySensorDetails(void)
{
  sensor_t sensor;
  mag.getSensor(&sensor);
  Serial.println("------------------------------------");
  Serial.print  ("Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
  Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
  Serial.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println(" uT");
  Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println(" uT");
  Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println(" uT");  
  Serial.println("------------------------------------");
  Serial.println("");
  delay(500);
}
void readDistance()
{
   

  // read the analog output of the EZ1 from analog input 0
  
  sensor1 = analogRead(A0);
  sensor2 = analogRead(A1);
  sensor3 = analogRead(A2);
  
  // convert the sensor reading to inches
  sensor1 = sensor1 / 2;
  sensor2 = sensor2 / 2;
  sensor3 = sensor3 / 2;
  Serial.println(sensor2);

}

void printOut_graphic(int input){
  int x;
 
  
  // print out a graphic representation of the result
  Serial.print(" ");
  for (x=0;x<(input/5);x++)
  {
    Serial.print(".");
  }
  Serial.println("|");

  // pause before taking the next reading

}



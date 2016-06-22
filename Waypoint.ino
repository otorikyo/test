void waypoint(int point_)
{
     //readGps();
     update_imu();
  
   switch (point_) {
  case 1:    // point 1
    Serial.println("point 0 >>>>>> 1");
          // Serial.print(lat_G); Serial.println(lon_G);
                        
                         // if (((lat_G>=461)&&(lat_G<=473))&&((lon_G>=418)&&(lon_G<=423)))
                         if (((lat_G>=latminPoint_1)&&(lat_G<=latmaxPoint_1))&&((lon_G>=lonminPoint_1)&&(lon_G<=lonmaxPoint_1)))
                         {
                           
                            
                            digitalWrite(pin_led_r,HIGH);
                            digitalWrite(pin_led_o,LOW);
                            digitalWrite(pin_led_w,HIGH);
                            /*
                           
                            robot_F(130,130);
                            delay(100);
                            robot_S();
                            delay(5000);
                            robot_L(130,130);
                            delay(250);
                            robot_S();
                            delay(500);
                            Serial.println("RUN######################################################");*/
                            nextpoint =2;
                            while(1){
                             Serial.println("Point1");
                             robot_S();
                            }
                           
                         }
                        
                        
                      else {      
                            digitalWrite(pin_led_r,LOW);
                            digitalWrite(pin_led_o,HIGH);
                            digitalWrite(pin_led_w,LOW);
                                do_pidCompass(yowPoint_0, 500, 1, 500);
                                //do_pidposition(15);
                                  //runWaypoint();
                                  nextpoint = 1;
                                   
                            }   
         
         
         
         
    break;
  case 2:    // point 2
    Serial.println("point 1 >>>>>>> 2");
    
                         // if (((lat_G>=461)&&(lat_G<=473))&&((lon_G>=418)&&(lon_G<=423)))
                         if (((lat_G>=latminPoint_2)&&(lat_G<=latmaxPoint_2))&&((lon_G>=lonminPoint_2)&&(lon_G<=lonmaxPoint_2)))
                         {
                          /// Serial.println("RUN######################################################");
                            robot_S();
                            digitalWrite(pin_led_r,HIGH);
                            digitalWrite(pin_led_o,LOW);
                            digitalWrite(pin_led_w,HIGH);
                            
                        
                            robot_F(130,130);
                            delay(100);
                            robot_S();
                            delay(1000);
                            robot_L(130,130);
                            delay(500); 
                            robot_S();
                            delay(100);
                            
                            nextpoint =3;
                           
                         }
                        
                        
                      else {      
                                   digitalWrite(pin_led_r,LOW);
                                   digitalWrite(pin_led_o,HIGH);
                                   digitalWrite(pin_led_w,LOW);
                                  do_pidCompass(yowPoint_1, 500, 1, 500);
                                  
                                  //runWaypoint();
                                  nextpoint = 2;
                                   
                            }   
         
    break;
    /*
  case 3:    // point 3
    Serial.println("point 2 >>>>>>> 3");
    
                     // if (((lat_G>=461)&&(lat_G<=473))&&((lon_G>=418)&&(lon_G<=423)))
                         if (((lat_G>=latminPoint_3)&&(lat_G<=latmaxPoint_3))&&((lon_G>=lonminPoint_3)&&(lon_G<=lonmaxPoint_3)))
                         {
                          /// Serial.println("RUN######################################################");
                            robot_S();
                            digitalWrite(pin_led_r,HIGH);
                            digitalWrite(pin_led_o,LOW);
                            digitalWrite(pin_led_w,HIGH);
                            
                            nextpoint =4;
                           
                         }
                        
                        
                      else {      
                             digitalWrite(pin_led_r,LOW);
                             digitalWrite(pin_led_o,HIGH);
                             digitalWrite(pin_led_w,LOW);
                            do_pidCompass(yowPoint_2, 500, 1, 500);
                            //runWaypoint();
                            nextpoint = 3;
                                   
                            }   
        
    break;
  case 4:    // point 4
    Serial.println("point 3 >>>>>>> 4");
    
                   // if (((lat_G>=461)&&(lat_G<=473))&&((lon_G>=418)&&(lon_G<=423)))
                         if (((lat_G>=latminPoint_4)&&(lat_G<=latmaxPoint_4))&&((lon_G>=lonminPoint_4)&&(lon_G<=lonmaxPoint_4)))
                         {
                          /// Serial.println("RUN######################################################");
                            robot_S();
                            digitalWrite(pin_led_r,HIGH);
                            digitalWrite(pin_led_o,LOW);
                            digitalWrite(pin_led_w,HIGH);
                            
                            nextpoint =5;
                           
                         }
                        
                        
                      else {      
                                   digitalWrite(pin_led_r,LOW);
                                   digitalWrite(pin_led_o,HIGH);
                                   digitalWrite(pin_led_w,LOW);
                                  do_pidCompass(yowPoint_3, 400, 1, 1000);
                                  //runWaypoint();
                                  nextpoint = 4;
                                   
                            }   
    break;
  case 5:    // point 5
    Serial.println("point 4 >>>>>>> 5");
    
                    // if (((lat_G>=461)&&(lat_G<=473))&&((lon_G>=418)&&(lon_G<=423)))
                         if (((lat_G>=latminPoint_5)&&(lat_G<=latmaxPoint_5))&&((lon_G>=lonminPoint_5)&&(lon_G<=lonmaxPoint_5)))
                         {
                          /// Serial.println("RUN######################################################");
                            robot_S();
                            digitalWrite(pin_led_r,HIGH);
                            digitalWrite(pin_led_o,LOW);
                            digitalWrite(pin_led_w,HIGH);
                            
                            nextpoint =5;
                           
                         }
                        
                        
                      else {      
                        
                           digitalWrite(pin_led_r,LOW);
                           digitalWrite(pin_led_o,HIGH);
                           digitalWrite(pin_led_w,LOW);
                           do_pidCompass(yowPoint_4, 400, 1, 1000);
                          //runWaypoint();
                           nextpoint = 4;
                                   
                            }   
         
    break;
    case 6:    // point 6
    Serial.println("point 5 >>>>>>> 6");
    
                    // if (((lat_G>=461)&&(lat_G<=473))&&((lon_G>=418)&&(lon_G<=423)))
                         if (((lat_G>=latminPoint_6)&&(lat_G<=latmaxPoint_6))&&((lon_G>=lonminPoint_6)&&(lon_G<=lonmaxPoint_6)))
                         {
                          /// Serial.println("RUN######################################################");
                            robot_S();
                            digitalWrite(pin_led_r,HIGH);
                            digitalWrite(pin_led_o,LOW);
                            digitalWrite(pin_led_w,HIGH);
                            
                            nextpoint =7;
                           
                         }
                        
                        
                      else {      
                        
                           digitalWrite(pin_led_r,LOW);
                           digitalWrite(pin_led_o,HIGH);
                           digitalWrite(pin_led_w,LOW);
                           do_pidCompass(yowPoint_5, 400, 1, 1000);
                          //runWaypoint();
                           nextpoint = 6;
                                   
                            }   
         
    break;
    case 7:    // point 7
    Serial.println("point 6 >>>>>>> 7");
    
                    // if (((lat_G>=461)&&(lat_G<=473))&&((lon_G>=418)&&(lon_G<=423)))
                         if (((lat_G>=latminPoint_7)&&(lat_G<=latmaxPoint_7))&&((lon_G>=lonminPoint_7)&&(lon_G<=lonmaxPoint_7)))
                         {
                          /// Serial.println("RUN######################################################");
                            robot_S();
                            digitalWrite(pin_led_r,HIGH);
                            digitalWrite(pin_led_o,LOW);
                            digitalWrite(pin_led_w,HIGH);
                            
                            nextpoint =8;
                           
                         }
                        
                        
                      else {      
                        
                           digitalWrite(pin_led_r,LOW);
                           digitalWrite(pin_led_o,HIGH);
                           digitalWrite(pin_led_w,LOW);
                           do_pidCompass(yowPoint_6, 400, 1, 1000);
                          //runWaypoint();
                           nextpoint = 7;
                                   
                            }   
         
    break;
    case 8:    // point 8
    Serial.println("point 7 >>>>>>> 8");
    
                    // if (((lat_G>=461)&&(lat_G<=473))&&((lon_G>=418)&&(lon_G<=423)))
                         if (((lat_G>=latminPoint_8)&&(lat_G<=latmaxPoint_8))&&((lon_G>=lonminPoint_8)&&(lon_G<=lonmaxPoint_8)))
                         {
                          /// Serial.println("RUN######################################################");
                            robot_S();
                            digitalWrite(pin_led_r,HIGH);
                            digitalWrite(pin_led_o,LOW);
                            digitalWrite(pin_led_w,HIGH);
                            
                            nextpoint =9;
                           
                         }
                        
                        
                      else {      
                        
                           digitalWrite(pin_led_r,LOW);
                           digitalWrite(pin_led_o,HIGH);
                           digitalWrite(pin_led_w,LOW);
                           do_pidCompass(yowPoint_7, 400, 1, 1000);
                          //runWaypoint();
                           nextpoint = 8;
                                   
                            }   
         
    break;
    case 9:    // point 9
    Serial.println("point 8 >>>>>>> 9");
    
                    // if (((lat_G>=461)&&(lat_G<=473))&&((lon_G>=418)&&(lon_G<=423)))
                         if (((lat_G>=latminPoint_9)&&(lat_G<=latmaxPoint_9))&&((lon_G>=lonminPoint_9)&&(lon_G<=lonmaxPoint_9)))
                         {
                          /// Serial.println("RUN######################################################");
                            robot_S();
                            digitalWrite(pin_led_r,HIGH);
                            digitalWrite(pin_led_o,LOW);
                            digitalWrite(pin_led_w,HIGH);
                            
                            nextpoint =10;
                           
                         }
                        
                        
                      else {      
                        
                           digitalWrite(pin_led_r,LOW);
                           digitalWrite(pin_led_o,HIGH);
                           digitalWrite(pin_led_w,LOW);
                           do_pidCompass(yowPoint_8, 400, 1, 1000);
                          //runWaypoint();
                           nextpoint = 9;
                                   
                            }   
         
    break;
    case 10:    // point 10
    Serial.println("point 9 >>>>>>> 10");
    
                    // if (((lat_G>=461)&&(lat_G<=473))&&((lon_G>=418)&&(lon_G<=423)))
                         if (((lat_G>=latminPoint_10)&&(lat_G<=latmaxPoint_10))&&((lon_G>=lonminPoint_10)&&(lon_G<=lonmaxPoint_10)))
                         {
                          /// Serial.println("RUN######################################################");
                            robot_S();
                            digitalWrite(pin_led_r,HIGH);
                            digitalWrite(pin_led_o,LOW);
                            digitalWrite(pin_led_w,HIGH);
                            
                            nextpoint =11;
                           
                         }
                        
                        
                      else {      
                        
                           digitalWrite(pin_led_r,LOW);
                           digitalWrite(pin_led_o,HIGH);
                           digitalWrite(pin_led_w,LOW);
                           do_pidCompass(yowPoint_9, 400, 1, 1000);
                          //runWaypoint();
                           nextpoint = 10;
                                   
                            }   
         
    break;
    case 11:    // point 7
    Serial.println("point 10 >>>>>>> 0");
    
                    // if (((lat_G>=461)&&(lat_G<=473))&&((lon_G>=418)&&(lon_G<=423)))
                         if (((lat_G>=latminPoint_0)&&(lat_G<=latmaxPoint_0))&&((lon_G>=lonminPoint_0)&&(lon_G<=lonmaxPoint_0)))
                         {
                          /// Serial.println("RUN######################################################");
                            robot_S();
                            digitalWrite(pin_led_r,HIGH);
                            digitalWrite(pin_led_o,LOW);
                            digitalWrite(pin_led_w,HIGH);
                            
                            nextpoint =0;
                           
                         }
                        
                        
                      else {      
                        
                           digitalWrite(pin_led_r,LOW);
                           digitalWrite(pin_led_o,HIGH);
                           digitalWrite(pin_led_w,LOW);
                           do_pidCompass(yowPoint_10, 400, 1, 1000);
                          //runWaypoint();
                           nextpoint = 11;
                                   
                            }   
         
     break;
    
    
    */
    
  } 




}  




/*

void waypoint(int point_)
{
   switch (point_) {
  case 1:    // point 1
    Serial.println("point 1");
         if(lastpoint == 0) ////////point 0 to point 1
         {
           
                        // Serial.print(lat_G); Serial.println(lon_G);
                        
                        // if (((lat_G>=461)&&(lat_G<=473))&&((lon_G>=418)&&(lon_G<=423)))
                         if (((lat_G>=latminPoint_1)&&(lat_G<=latmaxPoint_1))&&((lon_G>=lonminPoint_1)&&(lon_G<=lonmaxPoint_1)))
                         {
                          /// Serial.println("RUN######################################################");
                            robot_S();
                            digitalWrite(pin_led_r,HIGH);
                            digitalWrite(pin_led_o,LOW);
                            digitalWrite(pin_led_w,HIGH);
                            
                            lastpoint =0;
                            nextpoint =1;
                           
                         }
                        
                        
                      else {      
                                do_pidCompass(yowPoint_0, 400, 1, 1000);
                                  //runWaypoint();
                                  nextpoint = 1;
                                   
                            }   
                               
         }
         else if(lastpoint==1) ////////point 1 to point 2
         {
                  if (((lat_G>=latminPoint_2)&&(lat_G<=latmaxPoint_2))&&((lon_G>=lonminPoint_2)&&(lon_G<=lonmaxPoint_2)))
                         {
                          /// Serial.println("RUN######################################################");
                            robot_S();
                            digitalWrite(pin_led_r,HIGH);
                            digitalWrite(pin_led_o,LOW);
                            digitalWrite(pin_led_w,HIGH);
                            
                            robot_L(130,130);
                            delay(10);
                            lastpoint =1;
                            nextpoint =2;
                         }
                        
                        
                      else {      
                                  
                                  do_pidCompass(yowPoint_0, 400, 1, 1000);
                                  //runWaypoint();
                                  lastpoint =1;
                                  nextpoint = 1;
                            }   
         
         }
         else{
         
         }
    break;
  case 2:    // point 2
    Serial.println("point 2");
         if(lastpoint == 1) ////////point 1 to point 2
         {
             robot_S();
         }
         else if(lastpoint==2) ////////point 2 to point 3
         {
            robot_S();
         
         }
         else{
         
         }
    break;
  case 3:    // point 3
    Serial.println("point 3");
         if(lastpoint == 2)
         {
           
         }
         else if(lastpoint==3)
         {
         
         
         }
         else{
         
         }
    break;
  case 4:    // point 4
    Serial.println("point 4");
         if(lastpoint == 3)
         {
           
         }
         else if(lastpoint==4)
         {
         
         
         }
         else{
         
         }
    break;
  } 




}


*/

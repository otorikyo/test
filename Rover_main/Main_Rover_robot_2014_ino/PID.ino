///////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                  จากโปรเจคเก่า
//
///////////////////////////////////////////////////////////////////////////////////////////////////////



void do_pidposition(int target)
{
   
   //encoder0Pos = Serial.read();
  //encoder0Pos = 0;
 // target = Serial.read();
  //if (millis() - previousMillis > interval) 
   // if ( previousMillis < interval) 
  {
   //previousMillis = millis();   // remember the last time we blinked the LED
    
   // long error = encoder0Pos - target ; // find the error term of current position - target    //// For Encoder

    
    readDistance();
    long error = sensor2-target;         
    //generalized PID formula
    //correction = Kp * error + Kd * (error - prevError) + kI * (sum of errors)
   long ms = KP * error + KD * (error - lastError) +KI * (sumError);
  
   //////////////////////////////////////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////
//   // Serial.print ( ms , DEC);
//    //Serial.print ( " , " );
//       Serial.print ( encoder0Pos, DEC);
//       Serial.println ( " , " );
//       Serial.println ( "  " );
   // Serial.println ( error, DEC );
    
    lastError = error;    
    sumError += error;
    
    //scale the sum for the integral term
    if(sumError > iMax) 
    {
      sumError = iMax;
    } 
    else if(sumError < iMin)
    {
      sumError = iMin;
    }
    
    if(ms > 0)
    {
         
          //Motor_move(1,map(ms,0,1024,0,255));
     
        //  Motor_R(-map(ms,0,1024,0,255));
       //   Motor_L(map(ms,0,1024,0,255));  
       
      robot_L((ms,0,1024,0,255),(ms,0,1024,0,255));
       
       
    // Serial.println ( ms, DEC );     
    }
    if(ms < 0)
    {
        //  Motor_R(-map(ms,0,1024,0,255));
        //  Motor_L(map(ms,0,1024,0,255));   
          ms = -1 * ms;
          robot_R((ms,0,1024,0,255),(ms,0,1024,0,255)); 
  
//      Serial.println ( ms, DEC );
    }
   // if(ms == 0)
     if((ms==0)||(error<=1)||(error>=-1))
     
     {
       robot_F(170,170);
     // robot_S();;
//     // ms = -1 * ms;
    }
 
 
  }
  

}

void do_pidCompass(int target, int KP_, int KI_, int KD_)
{
  
   // int
   //encoder0Pos = Serial.read();
  //encoder0Pos = 0;
 // target = Serial.read();
  //if (millis() - previousMillis > interval) 
   // if ( previousMillis < interval) 
  {
   //previousMillis = millis();   // remember the last time we blinked the LED
    
   // long error = encoder0Pos - target ; // find the error term of current position - target    //// For Encoder

    
   /// readDistance();
  //   gatHMC5883();
   //  readGps();
   // headingDegrees_C= filter(headingDegrees_C);
//    Serial.print(headingDegrees_C);
    long error = yaw_imu-target; 
  //    Serial.print(lon_G);
   //   long error = lon_G-target; 

    //generalized PID formula
    //correction = Kp * error + Kd * (error - prevError) + kI * (sum of errors)
   long ms = KP_ * error + KD_ * (error - lastError_C) +KI_ * (sumError_C);
  
   //////////////////////////////////////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////
//   // Serial.print ( ms , DEC);
//    //Serial.print ( " , " );
//       Serial.print ( encoder0Pos, DEC);
//       Serial.println ( " , " );
//       Serial.println ( "  " );
   // Serial.println ( error, DEC );
    
    lastError_C = error;    
    sumError_C += error;
    
    //scale the sum for the integral term
    if(sumError_C > iMax_C) 
    {
      sumError_C = iMax_C;
    } 
    else if(sumError_C < iMin_C)
    {
      sumError_C = iMin_C;
    }
    
    if(ms > 0)
    {
         
          //Motor_move(1,map(ms,0,1024,0,255));
     
        //  Motor_R(-map(ms,0,1024,0,255));
       //   Motor_L(map(ms,0,1024,0,255));  
       
      robot_L((ms,0,1024,20,255),(ms,0,1024,20,255));
       
       
   //  Serial.println ("+++++" );     
    }
    if(ms < 0)
    {
        //  Motor_R(-map(ms,0,1024,0,255));
        //  Motor_L(map(ms,0,1024,0,255));   
          ms = -1 * ms;
          robot_R((ms,0,1024,20,255),(ms,0,1024,20,255)); 
  
    // Serial.println (" ----" );
    }
   // if(ms == 0)
     if((ms==0)||(error<=2)||(error>=-4))
     
     {
       robot_F(80,80);
     // robot_S();;
//     // ms = -1 * ms;
    }
 
 
  }      

}







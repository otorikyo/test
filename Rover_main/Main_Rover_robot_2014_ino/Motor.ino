/*
void Motor_moveA(int dir, byte pwm) 
{
   digitalWrite(pin_EN1,HIGH);
if(dir==0){
    digitalWrite(pin_1_motorA,HIGH);
    digitalWrite(pin_1_motorB,LOW);
    analogWrite( pin_speed_motorA, pwm);
  }
  else if(dir==1){
    digitalWrite(pin_1_motorA,LOW);
    digitalWrite(pin_1_motorB,HIGH);
    analogWrite( pin_speed_motorA,pwm);
  }
  else{
    digitalWrite(pin_1_motorA,LOW);
    digitalWrite(pin_1_motorB,LOW);
    analogWrite( pin_speed_motorA,255);
  }

}


void Motor_moveB(int dir, byte pwm) 
{
  digitalWrite(pin_EN2,HIGH);
if(dir==0){
    digitalWrite(pin_2_motorA,HIGH);
    digitalWrite(pin_2_motorB,LOW);
    analogWrite( pin_speed_motorB, pwm);
  }
  else if(dir==1){
    digitalWrite(pin_2_motorA,LOW);
    digitalWrite(pin_2_motorB,HIGH);
    analogWrite( pin_speed_motorB,pwm);
  }
  else{
    digitalWrite(pin_2_motorA,LOW);
    digitalWrite(pin_2_motorB,LOW);
    analogWrite( pin_speed_motorB,255);
  }

}


void Motor_Stop()
{

    digitalWrite(pin_1_motorA,LOW);
    digitalWrite(pin_2_motorA,LOW);
    digitalWrite(pin_1_motorB,LOW);
    digitalWrite(pin_2_motorB,LOW);
    analogWrite( pin_speed_motorA,255);
    analogWrite( pin_speed_motorB,255);

}


void Motor_move_pos_speed(char dir,int pos,int spd)
{
//  if(spd==0)Motor_move(dir,0);
//  else
//  {
//     dopid_speed(dir,spd);
//  }
 // Serial.println (encoder0Pos);
}

*/


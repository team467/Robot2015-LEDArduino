  int Gi = 10;
  int Ri = 11;
  int Bi = 9;
  
  int bit0 = 0;
  int bit1 = 1;
  int bit2 = 2;
  
void setup() {
  
}

void loop_debug() {
  //debug mode that links each digital input with a color channel if things are
  //not working as they should

  if (digitalRead(bit0) == HIGH)
  {
     analogWrite(Ri,255); 
  }
  else
  {
    analogWrite(Ri,0);
  }   
  if (digitalRead(bit1) == HIGH)
  {
     analogWrite(Gi,255); 
  }
  else
  {
    analogWrite(Gi,0);
  }   
  if (digitalRead(bit2) == HIGH)
  {
     analogWrite(Bi,255); 
  }
  else
  {
    analogWrite(Bi,0);
  }
}

void loop()
{
  


  if (digitalRead(bit0) == HIGH && digitalRead(bit1) == LOW && digitalRead(bit2) == LOW) {
    //rainbow mode that switches colors every 100 milleseconds, occurs during autonomous mode
    
      analogWrite(Ri, 255);
      analogWrite(Gi, 0);
      analogWrite(Bi, 0);
      delay(100);
      analogWrite(Ri, 255);
      analogWrite(Gi, 255);
      analogWrite(Bi, 0);
      delay(100);
      analogWrite(Ri, 0);
      analogWrite(Gi, 255);
      analogWrite(Bi, 0);
      delay(100);
      analogWrite(Ri, 0);
      analogWrite(Gi, 255);
      analogWrite(Bi, 255);
      delay(100);
      analogWrite(Ri, 0);
      analogWrite(Gi, 0);
      analogWrite(Bi, 255);
      delay(100);
      analogWrite(Ri, 255);
      analogWrite(Gi, 0);
      analogWrite(Bi, 255);
      delay(100);
  }

 else if (digitalRead(bit0) == LOW && digitalRead(bit1) == HIGH && digitalRead(bit2) == LOW) {
   //pulse of red that occurs during teleop while we are on the red alliance
      for (int i = 1; i <255; i++) {
      analogWrite(Ri, i);
      analogWrite(Gi, 0);
      analogWrite(Bi, 0);
      delay(1);
      }
      for (int i = 255; i > 1; i--) {
      analogWrite(Ri, i);
      analogWrite(Gi, 0);
      analogWrite(Bi, 0);
      delay(3);
      }  
  }
 else if (digitalRead(bit0) == HIGH && digitalRead(bit1) == HIGH && digitalRead(bit2) == LOW) {
   //pulse of blue that occurs during teleop while we are on the blue alliance
      for (int i = 1; i <255; i++) {
      analogWrite(Ri, 0);
      analogWrite(Gi, 0);
      analogWrite(Bi, i);
      delay(1);
      }
      for (int i = 255; i > 1; i--) {
      analogWrite(Ri, 0);
      analogWrite(Gi, 0);
      analogWrite(Bi, i);
      delay(3);
      } 
  }
  else if (digitalRead(bit0) == LOW && digitalRead(bit1) == LOW && digitalRead(bit2) == HIGH) {
    //pulse of yellow then blue that occurs while disabled
      for (int i = 1; i <255; i++) {
      analogWrite(Ri, i);
      analogWrite(Gi, i);
      analogWrite(Bi, 0);
      delay(1);
      }
      for (int i = 255; i > 1; i--) {
      analogWrite(Ri, i);
      analogWrite(Gi, i);
      analogWrite(Bi, 0);
      delay(3);
      }
     for (int i = 1; i <255; i++) {
      analogWrite(Ri, 0);
      analogWrite(Gi, 0);
      analogWrite(Bi, i);
      delay(1);
      }
      for (int i = 255; i > 1; i--) {
      analogWrite(Ri, 0);
      analogWrite(Gi, 0);
      analogWrite(Bi, i);
      delay(3);
      } 
  }
  else if (digitalRead(bit0) == LOW && digitalRead(bit1) == HIGH && digitalRead(bit2) == HIGH) {
    //pulse of yellow that occurs in the last 20 sec. of teleop
      for (int i = 1; i <255; i+=2) {
      analogWrite(Ri, i);
      analogWrite(Gi, i);
      analogWrite(Bi, 0);
      delay(1);
      }
      for (int i = 255; i > 1; i--) {
      analogWrite(Ri, i);
      analogWrite(Gi, i);
      analogWrite(Bi, 0);
      delay(1);
      }
  } 
  else if (digitalRead(bit0) == LOW && digitalRead(bit1) == LOW && digitalRead(bit2) == LOW) {
      analogWrite(Ri, 0);
      analogWrite(Gi, 0);
      analogWrite(Bi, 0);
  }
}

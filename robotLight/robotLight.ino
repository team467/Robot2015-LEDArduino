  int Gi = 10;
  int Ri = 11;
  int Bi = 9;
  
  int autoOut = 0;
  int teleopOut = 1;
  int warningOut = 2;
  
void setup() {
  
}

void loop_debug() {
  

  if (digitalRead(autoOut) == HIGH)
  {
     analogWrite(Ri,255); 
  }
  else
  {
    analogWrite(Ri,0);
  }   
  if (digitalRead(teleopOut) == HIGH)
  {
     analogWrite(Gi,255); 
  }
  else
  {
    analogWrite(Gi,0);
  }   
  if (digitalRead(warningOut) == HIGH)
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
  


  if (digitalRead(autoOut) == HIGH && digitalRead(teleopOut) == LOW && digitalRead(warningOut) == LOW) {
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

 else if (digitalRead(autoOut) == LOW && digitalRead(teleopOut) == HIGH && digitalRead(warningOut) == LOW) {
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
 else if (digitalRead(autoOut) == HIGH && digitalRead(teleopOut) == HIGH && digitalRead(warningOut) == LOW) {
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
  else if (digitalRead(autoOut) == LOW && digitalRead(teleopOut) == LOW && digitalRead(warningOut) == HIGH) {
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
  else if (digitalRead(autoOut) == LOW && digitalRead(teleopOut) == HIGH && digitalRead(warningOut) == HIGH) {
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
  else if (digitalRead(autoOut) == LOW && digitalRead(teleopOut) == LOW && digitalRead(warningOut) == LOW) {
      analogWrite(Ri, 0);
      analogWrite(Gi, 0);
      analogWrite(Bi, 0);
  }
}

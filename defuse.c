#include <Servo.h>

Servo myservo; 

int pos = 0;    

void setup() {
  myservo.attach(9); 
}

void loop() {
  
  for (pos = 0; pos <= 60; pos += 1) {
    myservo.write(pos); 
    delay(20);        
  }


  for (pos = 60; pos >= 0; pos -= 1) {
    myservo.write(pos);
   delay(20);
  }
}

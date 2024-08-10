// C++ code
//
 int ldrPin = A0; 
 int bzrPin = 3; 

int threshold = 50; 

void setup() {
  pinMode(ldrPin, INPUT);
  pinMode(bzrPin, OUTPUT);
}

void loop() {
  int ldrValue = analogRead(ldrPin);

  if (ldrValue > threshold) {
    tone(bzrPin, 120);
  } else {
    digitalWrite(bzrPin, LOW); 
    noTone(bzrPin);
  }
  delay(1000);
}

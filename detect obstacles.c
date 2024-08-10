#define trigPin 9
#define echoPin 8
#define thresholdDistance 320

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600); 
}

void loop() {
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
   delayMicroseconds(10);

  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;
Serial.println(distance);
  if (distance <= thresholdDistance) {
    Serial.println("Object detected!");}
    else
    {Serial.println("None");}
  

  delay(1000); 
}



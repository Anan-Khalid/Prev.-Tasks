#define leftMotorA 5 
#define leftMotorB 6  
#define rightMotorA 3
#define rightMotorB 4

void setup() {
  pinMode(leftMotorA, OUTPUT);
  pinMode(leftMotorB, OUTPUT);
  pinMode(rightMotorA, OUTPUT);
  pinMode(rightMotorB, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println("Turning Right");
  digitalWrite(leftMotorA, HIGH);
  digitalWrite(leftMotorB, LOW);
  digitalWrite(rightMotorA, LOW);
  digitalWrite(leftMotorB, HIGH);
  delay(7000);
  
  Serial.println("Turning Left");
  digitalWrite(leftMotorA, LOW);
  digitalWrite(leftMotorB, HIGH);
  digitalWrite(rightMotorA, HIGH);
  digitalWrite(leftMotorB, LOW);
  delay(7000);
  
  Serial.println("Moving Forward");
  digitalWrite(leftMotorA, HIGH);
  digitalWrite(leftMotorB, LOW);
  digitalWrite(rightMotorA, HIGH);
  digitalWrite(leftMotorB, LOW);
  delay(7000);
  
  Serial.println("Moving Backward");
  digitalWrite(leftMotorA, LOW);
  digitalWrite(leftMotorB, HIGH);
  digitalWrite(rightMotorA, LOW);
  digitalWrite(leftMotorB, HIGH);
  delay(7000);
  
}

   

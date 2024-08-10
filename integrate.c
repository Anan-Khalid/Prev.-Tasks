#include <Servo.h>

const int trigPin1 = A0;
const int echoPin1 = A1;
const int trigPin2 = A2;
const int echoPin2 = A3;
const int trigPin3 = A4;
const int echoPin3 = A5;
const int leftMotorPin1 = 5;
const int leftMotorPin2 = 6;
const int rightMotorPin1 = 9;
const int rightMotorPin2 = 10;
const int photoresistorPin = 12;
const int buzzerPin = 13;
const int servoPin = 11;
int pos = 0;

// Define grid dimensions and starting position
const int gridWidth = 50; 
const int gridHeight = 60; 
const int gridSquareSize = 10; 
int currentX = 0;
int currentY = 0;
int direction = 1; 

const int obstacleDistance = 15; 
const int lightThreshold = 50;

Servo myservo;

void setup() {
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(photoresistorPin, INPUT);
  Serial.begin(9600);
  myservo.attach(servoPin);
}

void loop() {
  long duration1, distance1;
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  int distanceFront = duration1 * 0.034 / 2;

  long duration2, distance2;
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  int distanceLeft = duration2 * 0.034 / 2;
  
  
  long duration3, distance3;
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  duration3 = pulseIn(echoPin3, HIGH);
  int distanceRight = duration3 * 0.034 / 2;

  int lightValue = analogRead(photoresistorPin);

  // Obstacle avoidance
  if (distanceFront < obstacleDistance) {
    stopMotors();
    delay(500);
    turnRight();
  } else if (distanceLeft < obstacleDistance) {
    stopMotors();
    delay(500);
    turnRight();
  } else if (distanceRight < obstacleDistance) {
    stopMotors();
    delay(500);
    turnLeft();
  }

  // Light detection
  if (lightValue > lightThreshold) {
    digitalWrite(buzzerPin, HIGH);
    Serial.println("Light detected at position: (" + String(currentX) + ", " + String(currentY) + ")");
    diffuse();
  } else {
    digitalWrite(buzzerPin, LOW);
  }

  // Movement
  switch (direction) {
    case 1: // Right
      turnRight();
      break;
    case 2: // Down
      moveForward();
      break;
    case 3: // Left
      turnLeft();
      break;
    case 4: // Up
      moveBackward();
      break;
  }

  
  // Print current position
  Serial.print("Current position: (");
  Serial.print(currentX);
  Serial.print(", ");
  Serial.print(currentY);
  Serial.println(")");
}

// Motor control functions
void moveForward() {
  digitalWrite(leftMotorPin1, HIGH);
  digitalWrite(leftMotorPin2, LOW);
  digitalWrite(rightMotorPin1, HIGH);
  digitalWrite(rightMotorPin2, LOW);
}

void moveBackward() {
  digitalWrite(leftMotorPin1, LOW);
  digitalWrite(leftMotorPin2, HIGH);
  digitalWrite(rightMotorPin1, LOW);
  digitalWrite(rightMotorPin2, HIGH);
}

void turnRight() {
  
  digitalWrite(leftMotorPin1, HIGH);
  digitalWrite(leftMotorPin2, LOW);
  digitalWrite(rightMotorPin1, LOW);
  digitalWrite(leftMotorPin2, HIGH);
  delay(1000);
}

void turnLeft() {
  digitalWrite(leftMotorPin1, LOW);
  digitalWrite(leftMotorPin2, HIGH);
  digitalWrite(rightMotorPin1, HIGH);
  digitalWrite(rightMotorPin2, LOW);
  delay(1000); 
}

void stopMotors() {
  digitalWrite(leftMotorPin1, LOW);
  digitalWrite(leftMotorPin2, LOW);
  digitalWrite(rightMotorPin1, LOW);
  digitalWrite(rightMotorPin2, LOW);
}

void diffuse() {
  for (pos = 0; pos <= 60; pos += 1) {
    myservo.write(pos); 
    delay(20);        
  }


  for (pos = 60; pos >= 0; pos -= 1) {
    myservo.write(pos);
   delay(20);
  }
}

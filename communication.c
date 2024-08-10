// Master
#include <Wire.h>

const int I2C_slaveAddress = 8;

void setup() {
  Wire.begin(); 
  Serial.begin(9600);
}

void loop() {
  // Receive data from I2C slave
  Wire.requestFrom(I2C_slaveAddress, 21); 
  String dataFromI2C = "";
  while (Wire.available()) {
    char c = Wire.read();
    dataFromI2C += c;
  }

  // Send data to serial slave
  Serial.println(dataFromI2C);

  // Receive data from serial slave
  if (Serial.available() > 0) {
    String dataFromSerial = Serial.readStringUntil('\n');
  }
}

// I2C Slave
#include <Wire.h>

const int slaveAddress = 8;

void setup() {
  Wire.begin(slaveAddress);
  Wire.onRequest(requestEvent); 
}

void loop() {
}

void requestEvent() {
  // Send data to master
  Wire.write("Hello from I2C slave!");
}

// Serial Slave
void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    String dataFromMaster = Serial.readStringUntil('\n');
    Serial.println("Received from Master: " + dataFromMaster);
  }
}

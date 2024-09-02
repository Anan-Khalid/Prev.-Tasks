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

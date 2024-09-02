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

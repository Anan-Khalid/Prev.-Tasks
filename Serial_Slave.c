void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    String dataFromMaster = Serial.readStringUntil('\n');
    Serial.println("Received from Master: " + dataFromMaster);
  }
}



void setup() {
  Serial.begin(115200);
  while(!Serial){

  }
}

// the loop function runs over and over again forever
void loop() {
  Serial.println("hello world!");
  delay(1000);
}

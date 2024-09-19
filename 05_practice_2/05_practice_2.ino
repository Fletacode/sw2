#define PIN_LED 7


unsigned int count,toggle;

void setup() {
  
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(PIN_LED, OUTPUT);
  
  Serial.begin(115200);
  while(!Serial){
    ;
  }
  
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(PIN_LED, toggle);  // turn the LED on (HIGH is the voltage level)
  delay(1000);
  while(1){
      //Serial.println(++count);
      toggle = toggle_state(toggle);
      digitalWrite(PIN_LED, toggle);  // turn the LED on (HIGH is the voltage level)
      delay(200);
  }                     
}

int toggle_state(int toggle){
  return !toggle;
}

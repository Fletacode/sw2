#define PIN_LED 9
#define PIN_TRIG 12
#define PIN_ECHO 13

#define SND_VEL 346.0 //거리 346m
#define INTERVAL 100
#define PULSE_DURATION 10
#define _DIST_MIN 100.0
#define _DIST_MAX 300.0

#define TIMEOUT ((INTERVAL / 2) * 1000.0)
#define SCALE (0.001 * 0.5 * SND_VEL) // 단위맞춰주기 위해서 * 왔다갔다하는거리 /2 * 거리


float USS_measure(int TRIG, int ECHO){
  digitalWrite(TRIG,HIGH);
  delayMicroseconds(PULSE_DURATION);
  digitalWrite(TRIG, LOW);

  return pulseIn(ECHO, HIGH, TIMEOUT) * SCALE; //아두이노 내장 함수
}

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  digitalWrite(PIN_TRIG,LOW);

  Serial.begin(57600);
}

// the loop function runs over and over again forever
void loop() {

  float distance = USS_measure(PIN_TRIG, PIN_ECHO);

  if ((distance == 0.0) || (distance > _DIST_MAX)){
    distance = _DIST_MAX + 10.0;
    digitalWrite(PIN_LED,1); //LED OFF
  }else if (distance < _DIST_MIN){
    distance = _DIST_MIN - 10.0;
    digitalWrite(PIN_LED,1); //LED_OFF
  }else{
    digitalWrite(PIN_LED,0); //LED_ON
  }

  Serial.print(" Min:"); Serial.print(_DIST_MIN);
  Serial.print(" distance:"); Serial.print(distance);
  Serial.print(" MAX:"); Serial.print(_DIST_MAX);
  Serial.println("");      

  delay(50);

  delay(INTERVAL);
}

enum {
  TRIG_PIN = 13,
  ECHO_PIN = 12,
  
  ECHO_DELAY = 2, //ms
  
  SERIAL_BAUD  = 9600,

  POLL_DELAY   = 300, //ms
  
  MIN_DISTANCE = 100, //Minimal distance to be considered as a trigger. cm
};

void setup() {
  Serial.begin (9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

}

void loop() {
  long duration, distance;
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(ECHO_DELAY);
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration/2) / 29.1;


  if (distance >= MIN_DISTANCE || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(POLL_DELAY);
}

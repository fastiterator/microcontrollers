/*
No hardware setup; requires the arduino board only.
*/


void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  int delayms, dir;
  float pct;
  for (delayms=50, pct=15.0, dir=1; ; ) {
    if (delayms<50 || delayms>520) { dir=-dir; }
    if (delayms<50) { delayms=50; }
    delayms +=  ( ( (int)  ( (float)delayms) * (pct/100.0) ) * dir );
    digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
    delay(delayms);                      // wait for a second
    digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
    delay(delayms);                      // wait for a second
  }
}

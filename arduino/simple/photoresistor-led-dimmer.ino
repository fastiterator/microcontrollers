/*
wiring:
pico-gnd -> bb-gnd
pico-5v -> bb-pwr
pico-a0 -> bb-i3
pico-p3 -> bb-j18
bb-pwr -> bb-h2
bb-gnd -> bb-h8
bb-gnd -> bb-j23

parts on bb:
photoresistor: bb-f2 -> bb-f3
resistor: bb-g3 -> bb-g8
resistor: bb-f18 -> bb-f22
led: longleg = bb-g22 -> shortleg = bb-g23
*/

int i=0;

void setup() {
  Serial.begin(9600);
  Serial.println("\nrestart");
  pinMode(3, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(A0);
  Serial.print(sensorValue);
  Serial.print(" ");
  Serial.print(i);
  Serial.println();
  if (sensorValue < 500) {
    i+=3;
    if (i>255) { i=255; }
  } else {
    i-=3;
    if (i<0) { i=0; }
  }
  analogWrite(3,i);
  delay(20);
}

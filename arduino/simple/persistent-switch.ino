/*
setup:
- vcc & ground to breadboard (bb) from arduino
- bb-vcc -> switch-upper-left-leg
- switch-lower-right-leg ->
    10K-ohm-resistor -> bb-gnd
    ard-pin2
- ard-pin7 -> led-short-leg
- led-long-leg -> 200-ohm-resistor-leg0
- 200-ohm-resistor-leg1 -> bb-gnd
*/

int val=0;
int last=0;
int switchmode=0;
char *strp[]={"\noff","\non"};
int pinmodes[]={LOW,HIGH};

void setup() {
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(2, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.print("\n\n");
  setmode(LOW);
}

void setmode(int mode) {
  Serial.print(strp[switchmode]);
  digitalWrite(7,pinmodes[switchmode]);
  digitalWrite(LED_BUILTIN,pinmodes[switchmode]);
}

void loop() {
  val = digitalRead(2);
  if (val == last) {
    Serial.print(".");
  } else {
    last=val;
    if (val == HIGH) {
      switchmode=(switchmode+1)%2;
      setmode(switchmode);
    }
  }
  delay(20);
}

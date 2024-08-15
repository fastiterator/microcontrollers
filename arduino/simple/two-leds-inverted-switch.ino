/*
hardware setup:
- momentary switch wired to digital pin 2 (input)
- led wired to digital pin 7 (output)
/*

int val=0;
int last=0;
char *strp[]={"\noff","\non"};
int pinmodes[]={LOW,HIGH};

void setup() {
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(2, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.print(strp[0]);
}

void loop() {
  val = digitalRead(2);
  if (val == last) {
    Serial.print(".");
  } else {
    last=val;
    Serial.print(strp[val]);
    digitalWrite(7,pinmodes[val]);
    digitalWrite(LED_BUILTIN,pinmodes[(val+1)%2]);
  }
  delay(20);
}

const int botonPin = 3;
const int ledPin = 7;
void setup() {
  pinMode(botonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int buttonState=digitalRead(botonPin);
  digitalWrite(ledPin, buttonState);
}

const int dataPin  = 11; // SER
const int clockPin = 13; // SRCLK
const int latchPin = 8;  // RCLK
const byte patterns[] = {
  0b10000000, // 
  0b01000000,
  0b00100000, // 
  0b00010000,
  0b00001000, // 
  0b00000100,  //
  0b00000010,  //
  0b00000001  //
};
void setup() {
  pinMode(dataPin,  OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
}

void loop() {
  for (byte i = 0; i < sizeof(patterns); ++i) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, patterns[i]);
    digitalWrite(latchPin, HIGH);
    delay(1000);
  }
}

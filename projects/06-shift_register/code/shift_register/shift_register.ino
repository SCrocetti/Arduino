const int dataPin  = 11; // SER
const int clockPin = 13; // SRCLK
const int latchPin = 8;  // RCLK
const byte patterns[] = {
  0b10101010, // alternating
  0b01010101,
  0b11110000, // nibble flash
  0b00001111,
  0b10000001, // edges
  0b01111110  // center bar
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
    delay(300);
  }
}

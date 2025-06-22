const int ledPinPositive = 10;
const int ledPinNegative = 11;
void setup() {
  pinMode(ledPinPositive, OUTPUT);
  pinMode(ledPinNegative, OUTPUT);
}

void loop() {
    digitalWrite(ledPinPositive, HIGH);
    digitalWrite(ledPinNegative, LOW);

    delay(500);


    digitalWrite(ledPinPositive,LOW );
    digitalWrite(ledPinNegative, HIGH);
     delay(500);
}

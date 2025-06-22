const bool on = true;
const long delay_time = 300;
void setup() {
  // Set all pins conected to the led matrix to output
  // we only controll rows 2 to 7 and columns 2 to 7
  for(int i=2;i<14;i++){
    pinMode(i, OUTPUT);
  }
  // Set all catode (odd) pines to high so those leds wont fire whe their row is on high
  for(int i=3;i<14;i+=2){
    digitalWrite(i,HIGH);
  }
}

void loop() {
  // even pins are anode for the leds witch are the rows of the matrix
  for(int i=2;i<13;i+=2){
    // odd pins are catode for the leds witch are the columns of the matrix
    for(int j=3;j<14;j+=2){
      digitalWrite(i,HIGH);
      digitalWrite(j,LOW);
      delay(delay_time);


      digitalWrite(i,LOW);
      digitalWrite(j,HIGH);
    }

  }
}

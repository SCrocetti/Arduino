const bool on = false;
const long delay_time = 100;
const int filablanca1 = 2;
const int filablanca2 = 3;
const int filanegra1 = 8;
const int filanegra2 = 9;
void setup() {
  // put your setup code here, to run once:
  for(int i=2;i<10;i++){
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if (on){
    for(int i=2;i<10;i++){
      digitalWrite(i, HIGH);
      if(i==filablanca1 || i==filablanca2 || i==filanegra1 || i==filanegra2){
        continue;
      }
      delay(delay_time);
      digitalWrite(i, LOW);
      delay(delay_time);
    }
    delay(delay_time);

    for(int i=2;i<10;i++){
      if(i==filablanca1 || i==filablanca2 || i==filanegra1 || i==filanegra2){
        digitalWrite(i, LOW);
      }
    }
    delay(delay_time);
  }
}

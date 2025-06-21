const bool on = true;
const long delay_time = 300;
void setup() {
  // put your setup code here, to run once:
  for(int i=2;i<14;i++){
    pinMode(i, OUTPUT);
  }
  for(int i=3;i<14;i+=2){
    digitalWrite(i,HIGH);
  }
}

void loop() {
  for(int i=2;i<13;i+=2){
    for(int j=3;j<14;j+=2){
      digitalWrite(i,HIGH);
      digitalWrite(j,LOW);
      delay(delay_time);


      digitalWrite(i,LOW);
      digitalWrite(j,HIGH);
    }

  }
}

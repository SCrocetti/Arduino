const int botonPin = 3;
const int ledPin = 10;
int estadoBoton = 0;
bool system_on=false;
void setup() {
  pinMode(botonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  estadoBoton = digitalRead(botonPin);
  delay(500);
  if (estadoBoton == HIGH) {
    Serial.println("Botón presionado");
    system_on=!system_on;
  } else {
    Serial.println("Botón liberado");
  }
  if(system_on){
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
  }
  else{
    digitalWrite(ledPin, LOW);
  }
}
/**
 * Project: Improved Toggle LED System
 * Description: Uses state change detection and non-blocking timing.
 */

const int BUTTON_PIN = 3;
const int LED_PIN = 10;

// State Variables
bool systemIsActive = false;
int lastButtonState = LOW;

// Timing Variables (Non-blocking)
unsigned long lastBlinkTime = 0;
const int blinkInterval = 500; // Blink every 500ms
bool ledState = LOW;

void setup() {
  pinMode(BUTTON_PIN, INPUT); // Consider using INPUT_PULLUP if button is wired to GND
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  checkButton();
  
  if (systemIsActive) {
    runBlinkLogic();
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}

void checkButton() {
  int currentButtonState = digitalRead(BUTTON_PIN);

  // Check if the button state changed from LOW to HIGH (The "Edge")
  if (currentButtonState == HIGH && lastButtonState == LOW) {
    systemIsActive = !systemIsActive;
    Serial.print("System Active: ");
    Serial.println(systemIsActive ? "ON" : "OFF");
    
    delay(50); // Simple "Debounce" to ignore electrical noise
  }
  
  lastButtonState = currentButtonState;
}

void runBlinkLogic() {
  unsigned long currentMillis = millis();
  
  // Blink without using delay()
  if (currentMillis - lastBlinkTime >= blinkInterval) {
    lastBlinkTime = currentMillis;
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);
  }
}
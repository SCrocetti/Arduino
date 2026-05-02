/**
 * Project: Toggle LED System
 * Description: Toggles a system state using a momentary push button. 
 * When systemIsActive is true, the LED blinks.
 */

// --- Configuration Constants ---
const int BUTTON_PIN = 3;     // The digital pin connected to the push button
const int LED_PIN = 10;       // The digital pin connected to the LED

// --- State Variables ---
int buttonState = 0;          // Current reading from the button input
bool systemIsActive = false;  // Toggle flag to track if the system is ON or OFF

void setup() {
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  
  // Initialize serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Read the current state of the button
  buttonState = digitalRead(BUTTON_PIN);
  
  // Small delay to help with primitive debouncing
  delay(500);

  if (buttonState == HIGH) {
    Serial.println("Button pressed");
    // Toggle the system state (ON becomes OFF, vice versa)
    systemIsActive = !systemIsActive;
  } else {
    Serial.println("Button released");
  }

  // --- System Logic ---
  if (systemIsActive) {
    // If the system is active, blink the LED
    digitalWrite(LED_PIN, HIGH);
    delay(500);
    digitalWrite(LED_PIN, LOW);
  } else {
    // Ensure the LED is off when the system is inactive
    digitalWrite(LED_PIN, LOW);
  }
}
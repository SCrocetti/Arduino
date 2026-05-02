/**
 * Project: 02 - Relay DC Switching
 * Description: Basic digital input/output to control a relay via a tactile button.
 * License: MIT
 */

// Pin Definitions
const int buttonPin = 3;  // Digital input for the tactile switch
const int relayPin = 7;   // Digital output for the relay module

void setup() {
  // Initialize pins
  pinMode(buttonPin, INPUT);
  pinMode(relayPin, OUTPUT);
  
  // Ensure relay starts in a known state (OFF)
  digitalWrite(relayPin, LOW);
}

void loop() {
  // Read the current state of the button
  int buttonState = digitalRead(buttonPin);
  
  // Drive the relay state based on the button input
  // Note: This follows the button state directly (Momentary)
  digitalWrite(relayPin, buttonState);
}
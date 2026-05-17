/*
 * Project: 03 - Full 8x8 Matrix Sweep
 * Description: Sequential sweep of full 8x8 LED Matrix.
 * Connections: 
 * - Even pins (2-16) -> Rows (Anodes)
 * - Odd pins (3-17)  -> Columns (Cathodes)
 */

const long delay_time = 300;

void setup() {
  // Set all pins connected to the LED matrix as OUTPUT (Pins 2 to 13)
  for (int i = 2; i < 18; i++) {
    pinMode(i, OUTPUT);
  }

  // Set all cathode pins (ODD) to HIGH to ensure LEDs are OFF initially
  // In a common anode matrix, the cathode must be LOW to complete the circuit
  for (int i = 3; i < 18; i += 2) {
    digitalWrite(i, HIGH);
  }
}

void loop() {
  // OUTER LOOP: Iterates through even pins (Rows / Anodes)
  for (int i = 2; i < 18; i += 2) {
    // Activate Row
    digitalWrite(i, HIGH); 
    // INNER LOOP: Iterates through odd pins (Columns / Cathodes)
    for (int j = 3; j < 18; j += 2) {
      
       // Activate Column (Sink current)
      digitalWrite(j, LOW); 
      
      delay(delay_time);
      
       // Deactivate Column (Sink current)
      digitalWrite(j, HIGH); 
    }
    // Deactivate Row
    digitalWrite(i, LOW);
  }
}
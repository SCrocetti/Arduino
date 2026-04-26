/*
 * Project: 03 - Inner 6x6 Matrix Sweep
 * Description: Sequential sweep of the inner 6x6 grid of an 8x8 LED Matrix.
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
    
    // INNER LOOP: Iterates through odd pins (Columns / Cathodes)
    for (int j = 3; j < 18; j += 2) {
      
      // Turn ON the target LED
      digitalWrite(i, HIGH); // Activate Row
      digitalWrite(j, LOW);  // Activate Column (Sink current)
      
      delay(delay_time);

      // Turn OFF the target LED (Prepare for the next one)
      digitalWrite(i, LOW);
      digitalWrite(j, HIGH);
    }
  }
}
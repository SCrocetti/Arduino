#include <LedMatrixAndShiftRegisterDrawer.h>
#include <Arduino.h>
#include <avr/pgmspace.h>

struct Node {
    int x, y;
    Node* next;
    Node(int xVal, int yVal) : x(xVal), y(yVal), next(nullptr) {}
};

class Snake {
private:
    Node* head;
public:
    
    Snake() : head(nullptr) {}

    // Add to the front (head)
    void push(int x, int y) {
        Node* newNode = new Node(x, y);
        newNode->next = head;
        head = newNode;
    }

    // Remove from the end (tail)
    void pop() {
        if (!head) {
            return;
        }

        if (!head->next) {
            // Only one element
            delete head;
            head = nullptr;
            return;
        }

        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }

        delete current->next;
        current->next = nullptr;
    }
    bool isCollidingWithSelf(){
      if(!head) return false;
      Node* current=head->next;
      while (current!=nullptr) {
          if (head->x == current->x && head->y == current->y){
            return true;
          }
          current = current->next;
      }
      return false;
    }
    Node* getHead() const {
        return head;
    }
    ~Snake() {
        while (head) {
            pop();
        }
    }
};

Snake snake;

constexpr uint8_t DATA_PIN  = 10;        // 74HC595 SER
constexpr uint8_t CLOCK_PIN = 12;        // 74HC595 SRCLK
constexpr uint8_t LATCH_PIN = 11;        // 74HC595 RCLK
constexpr uint8_t ROW_PINS[8] = {2, 3, 4, 5, 6, 7, 8, 9}; // Matrix rows

LedMatrixAndShiftRegisterDrawer drawer(ROW_PINS,DATA_PIN, CLOCK_PIN, LATCH_PIN);
// pins of the buttons are connected in the following order:
// UP,DOWN,LEFT, RIGHT
constexpr uint8_t BUTTON_PINS[4]={A0,A1,A2,A3};

bool snake_has_eaten=false;
bool GAME_STATE[8][8];
uint8_t head_next_position[2]={5,4};
uint8_t food_position[2];
int8_t deltaX=1;
int8_t deltaY=0;
unsigned long availableImputTime = 2000; 
unsigned long lastInputCheck = 0;
void updateGameState() {
  // 1. Clear the board
  for (int y = 0; y < 8; ++y)
    for (int x = 0; x < 8; ++x)
      GAME_STATE[y][x] = 0;

  // 2. Mark the snake body
  Node* current = snake.getHead();
  while (current != nullptr) {
    GAME_STATE[current->y][current->x] = 1;
    current = current->next;
  }

  // 3. Mark the food position
  if (food_position[0] != 0xFF && food_position[1] != 0xFF) {
    GAME_STATE[food_position[1]][food_position[0]] = 1;
  }
}

void generateFood() {
  

  uint8_t emptyX[64], emptyY[64];
  int count = 0;

  for (uint8_t y = 0; y < 8; ++y) {
    for (uint8_t x = 0; x < 8; ++x) {
      if (GAME_STATE[y][x] == 0) {
        emptyX[count] = x;
        emptyY[count] = y;
        count++;
      }
    }
  }

  if (count == 0) {
    // No space left — game over?
    food_position[0] = 0xFF;
    food_position[1] = 0xFF;
    return;
  }

  // 4. Choose random empty cell
  int r = random(count);
  food_position[0] = emptyX[r];
  food_position[1] = emptyY[r];
  updateGameState();
}
void drawGameState() {
    uint8_t ledMatrixState[8];
    for (uint8_t y = 0; y < 8; ++y) {
        uint8_t row = 0;
        for (uint8_t x = 0; x < 8; ++x) {
            row |= (GAME_STATE[y][x] ? 1 : 0) << (7 - x);
        }
        ledMatrixState[y] = row;
    }
    // call your LED drawing function here, e.g.:
    drawer.drawPattern(ledMatrixState);
}
void setup() {
  drawer.begin();
  for(uint8_t button=0;button<4;button++){
    pinMode(BUTTON_PINS[button], INPUT);
  }
  Serial.begin(9600);

  snake.push(4, 4);
  snake.push(3, 4);

  generateFood();
}
void loop() {
  Node* head = snake.getHead();

  // --- Always check input ---
  if (deltaX != 0) {
    int up = digitalRead(BUTTON_PINS[0]);
    int down = digitalRead(BUTTON_PINS[1]);
    if (up == HIGH && down == LOW && deltaY != 1) {
      deltaX = 0;
      deltaY = -1;
    } else if (down == HIGH && up == LOW && deltaY != -1) {
      deltaX = 0;
      deltaY = 1;
    }
  } else {
    int left = digitalRead(BUTTON_PINS[2]);
    int right = digitalRead(BUTTON_PINS[3]);
    if (left == HIGH && right == LOW && deltaX != 1) {
      deltaX = -1;
      deltaY = 0;
    } else if (right == HIGH && left == LOW && deltaX != -1) {
      deltaX = 1;
      deltaY = 0;
    }
  }

  // --- Game state update only at intervals ---
  unsigned long now = millis();
  if (now - lastInputCheck >= availableImputTime) {
    lastInputCheck = now;

    head_next_position[0]=head->x+deltaX;
    head_next_position[1]=head->y+deltaY;

    snake.push(head_next_position[0], head_next_position[1]);

    head = snake.getHead();
    if (food_position[0] == head->x && food_position[1] == head->y) {
      snake_has_eaten = true;
    }

    if (!snake_has_eaten) {
      snake.pop();
      updateGameState();
    } else {
      generateFood();
      snake_has_eaten = false;
    }


    if (head->x >= 8 || head->y >= 8 || head->x <= -1 || head->y <= -1) {
      Serial.println("Game Over: Out of bounds");
      Serial.flush();
      while (true);
    }

    if (snake.isCollidingWithSelf()) {
      Serial.println("Game Over: Collision with self");
      Serial.flush();
      while (true);
    }
  }
  drawGameState();
}

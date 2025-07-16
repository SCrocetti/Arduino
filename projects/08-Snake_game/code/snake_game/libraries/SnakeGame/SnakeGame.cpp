#include "SnakeGame.h"

SnakeGame::SnakeGame(
    const uint8_t* rowPins,
    uint8_t dataPin,
    uint8_t clockPin,
    uint8_t latchPin,
    const uint8_t* buttonPins,
    unsigned long inputInterval
)
    : buttonPins(buttonPins),
      availableInputTime(inputInterval),
      drawer(rowPins, dataPin, clockPin, latchPin) {}

void SnakeGame::begin() {
    drawer.begin();
    for (uint8_t i = 0; i < 4; i++) {
        pinMode(buttonPins[i], INPUT);
    }

    snake.push(4, 4);
    snake.push(3, 4);

    generateFood();
}

void SnakeGame::update() {
    handleInput();

    unsigned long now = millis();
    if (now - lastInputCheck >= availableInputTime) {
        lastInputCheck = now;

        Node* head = snake.getHead();
        head_next_position[0] = head->x + deltaX;
        head_next_position[1] = head->y + deltaY;

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

        if (checkCollision()) {
            while (true); // Halt on game over
        }
    }
    draw();
}

void SnakeGame::handleInput() {
    if (deltaX != 0) {
        int up = digitalRead(buttonPins[0]);
        int down = digitalRead(buttonPins[1]);
        if (up == HIGH && down == LOW && deltaY != 1) {
            deltaX = 0;
            deltaY = -1;
        } else if (down == HIGH && up == LOW && deltaY != -1) {
            deltaX = 0;
            deltaY = 1;
        }
    } else {
        int left = digitalRead(buttonPins[2]);
        int right = digitalRead(buttonPins[3]);
        if (left == HIGH && right == LOW && deltaX != 1) {
            deltaX = -1;
            deltaY = 0;
        } else if (right == HIGH && left == LOW && deltaX != -1) {
            deltaX = 1;
            deltaY = 0;
        }
    }
}

bool SnakeGame::checkCollision() {
    Node* head = snake.getHead();

    if (head->x < 0 || head->y < 0 || head->x >= 8 || head->y >= 8) {
        return true;
    }

    if (snake.isCollidingWithSelf()) {
        return true;
    }

    return false;
}

void SnakeGame::updateGameState() {
    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            GAME_STATE[y][x] = 0;
        }
    }

    Node* current = snake.getHead();
    while (current != nullptr) {
        GAME_STATE[current->y][current->x] = 1;
        current = current->next;
    }

    if (food_position[0] != 0xFF && food_position[1] != 0xFF) {
        GAME_STATE[food_position[1]][food_position[0]] = 1;
    }
}

void SnakeGame::generateFood() {
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
        food_position[0] = 0xFF;
        food_position[1] = 0xFF;
        return;
    }

    int r = random(count);
    food_position[0] = emptyX[r];
    food_position[1] = emptyY[r];
    updateGameState();
}

void SnakeGame::draw() {
    uint8_t ledMatrixState[8];
    for (uint8_t y = 0; y < 8; ++y) {
        uint8_t row = 0;
        for (uint8_t x = 0; x < 8; ++x) {
            row |= (GAME_STATE[y][x] ? 1 : 0) << (7 - x);
        }
        ledMatrixState[y] = row;
    }
    drawer.drawPattern(ledMatrixState);
}

#pragma once

#include <Arduino.h>
#include <LedMatrixAndShiftRegisterDrawer.h>
#include "Snake.h"

class SnakeGame {
public:
    SnakeGame(
        const uint8_t* rowPins,
        uint8_t dataPin,
        uint8_t clockPin,
        uint8_t latchPin,
        const uint8_t* buttonPins,
        unsigned long inputInterval = 750
    );
    void begin();
    void update();

private:
    void handleInput();
    void updateGameState();
    void generateFood();
    bool checkCollision();
    void draw();

    // Configurable pins (only keep what you use later)
    const uint8_t* buttonPins;

    // Timing
    unsigned long availableInputTime;
    unsigned long lastInputCheck = 0;

    // Game state
    bool GAME_STATE[8][8];
    bool snake_has_eaten = false;
    uint8_t head_next_position[2] = {5, 4};
    uint8_t food_position[2] = {0xFF, 0xFF};
    int8_t deltaX = 1;
    int8_t deltaY = 0;

    // Game objects
    Snake snake;
    LedMatrixAndShiftRegisterDrawer drawer;
};

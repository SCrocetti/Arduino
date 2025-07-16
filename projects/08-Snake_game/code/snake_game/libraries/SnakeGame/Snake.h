#pragma once

/**
 * Represents a single segment of the snake's body.
 */
struct Node {
    int x, y;       ///< Position of the segment on the grid
    Node* next;     ///< Pointer to the next segment

    Node(int xVal, int yVal) : x(xVal), y(yVal), next(nullptr) {}
};

/**
 * A class that manages the snake's body and movement logic.
 */
class Snake {
private:
    Node* head; ///< Pointer to the head (front) of the snake

public:
    /**
     * Constructor: Initializes an empty snake.
     */
    Snake();

    /**
     * Destructor: Frees all memory used by the snake's body.
     */
    ~Snake();

    /**
     * Adds a new segment at the front (head) of the snake.
     * 
     * @param x The x-coordinate of the new head segment.
     * @param y The y-coordinate of the new head segment.
     */
    void push(int x, int y);

    /**
     * Removes the last segment (tail) of the snake.
     * 
     * This is used to move the snake forward unless it has eaten.
     */
    void pop();

    /**
     * Checks if the snake's head is colliding with any part of its own body.
     * 
     * @return true if there is a collision with itself, false otherwise.
     */
    bool isCollidingWithSelf();

    /**
     * Returns a pointer to the current head node of the snake.
     * 
     * @return Pointer to the head Node.
     */
    Node* getHead() const;
};

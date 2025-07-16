#include "Snake.h"

Snake::Snake() : head(nullptr) {}

Snake::~Snake() {
    while (head) {
        pop();
    }
}

void Snake::push(int x, int y) {
    Node* newNode = new Node(x, y);
    newNode->next = head;
    head = newNode;
}

void Snake::pop() {
    if (!head) return;

    if (!head->next) {
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

bool Snake::isCollidingWithSelf() {
    if (!head) return false;

    Node* current = head->next;
    while (current != nullptr) {
        if (head->x == current->x && head->y == current->y) {
            return true;
        }
        current = current->next;
    }

    return false;
}

Node* Snake::getHead() const {
    return head;
}

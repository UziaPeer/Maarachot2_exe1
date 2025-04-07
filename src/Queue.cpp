// src/Queue.cpp
// Email: peeruzia@gmail.com
#include "Queue.hpp"
#include <stdexcept>

namespace graph {

// בנאי - מקצה מערך ומאתחל את המשתנים
Queue::Queue(int cap) : capacity(cap), front(0), rear(0), size(0) {
    data = new int[capacity];
}

// דסטרקטור - משחרר את הזיכרון של המערך
Queue::~Queue() {
    delete[] data;
}

// מוסיף איבר לסוף התור
void Queue::enqueue(int value) {
    if (size == capacity) {
        throw std::runtime_error("Queue is full"); // התור מלא
    }
    data[rear] = value;
    rear = (rear + 1) % capacity; // התור עיגולי
    ++size;
}

// מוציא איבר מההתחלה של התור
int Queue::dequeue() {
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty"); // לא ניתן להוציא מאחד ריק
    }
    int val = data[front];
    front = (front + 1) % capacity;
    --size;
    return val;
}

// בודק אם התור ריק
bool Queue::isEmpty() const {
    return size == 0;
}

} 


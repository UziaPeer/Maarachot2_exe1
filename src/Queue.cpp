// src/Queue.cpp
// Email: peeruzia@gmail.com
#include "Queue.hpp"
#include <stdexcept>

namespace graph {

Queue::Queue(int cap) : capacity(cap), front(0), rear(0), size(0) {
    data = new int[capacity];
}

Queue::~Queue() {
    delete[] data;
}

void Queue::enqueue(int value) {
    if (size == capacity) {
        throw std::runtime_error("Queue is full");
    }
    data[rear] = value;
    rear = (rear + 1) % capacity;
    ++size;
}

int Queue::dequeue() {
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty");
    }
    int val = data[front];
    front = (front + 1) % capacity;
    --size;
    return val;
}

bool Queue::isEmpty() const {
    return size == 0;
}

} // namespace graph

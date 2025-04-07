// include/Queue.hpp
// Email: peeruzia@gmail.com
#ifndef QUEUE_HPP
#define QUEUE_HPP

namespace graph {

class Queue {
private:
    int* data;
    int front;
    int rear;
    int size;
    int capacity;

public:
    Queue(int capacity);
    ~Queue();
    void enqueue(int value);
    int dequeue();
    bool isEmpty() const;
};

} // namespace graph

#endif // QUEUE_HPP

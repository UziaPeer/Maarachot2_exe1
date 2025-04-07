// include/PriorityQueue.hpp
// Email: peeruzia@gmail.com
#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP

namespace graph {

struct PQNode {
    int vertex;
    int priority;
};

class PriorityQueue {
private:
    PQNode* heap;
    int capacity;
    int size;

    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    PriorityQueue(int cap);
    ~PriorityQueue();
    void insert(int vertex, int priority);
    int extractMin();
    bool isEmpty() const;
    void decreaseKey(int vertex, int newPriority);
    bool contains(int vertex) const;
};

} // namespace graph

#endif // PRIORITYQUEUE_HPP

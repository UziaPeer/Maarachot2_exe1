// src/PriorityQueue.cpp
// Email: peeruzia@gmail.com
#include "PriorityQueue.hpp"
#include <stdexcept>

namespace graph {

// בנאי - מקצה מערך לפי קיבולת
PriorityQueue::PriorityQueue(int cap) : capacity(cap), size(0) {
    heap = new PQNode[capacity];
}

// דסטרקטור - משחרר את המערך
PriorityQueue::~PriorityQueue() {
    delete[] heap;
}

// פונקציה פנימית - מאזנת כלפי מעלה אם נוספה עדיפות נמוכה יותר מההורה
void PriorityQueue::heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent].priority > heap[index].priority) {
            PQNode temp = heap[parent];
            heap[parent] = heap[index];
            heap[index] = temp;
            index = parent;
        } else break;
    }
}

// פונקציה פנימית - מאזנת כלפי מטה אם נדרשת החלפה עם ילד קטן יותר
void PriorityQueue::heapifyDown(int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left].priority < heap[smallest].priority)
        smallest = left;
    if (right < size && heap[right].priority < heap[smallest].priority)
        smallest = right;

    if (smallest != index) {
        PQNode temp = heap[smallest];
        heap[smallest] = heap[index];
        heap[index] = temp;
        heapifyDown(smallest);
    }
}

// מוסיף קודקוד עם עדיפות (אם יש מקום)
void PriorityQueue::insert(int vertex, int priority) {
    if (size == capacity) throw std::runtime_error("PriorityQueue is full");
    heap[size] = {vertex, priority};
    heapifyUp(size);
    ++size;
}

// מחזיר את הקודקוד עם העדיפות הכי גבוהה (כלומר עם הערך הכי נמוך)
int PriorityQueue::extractMin() {
    if (isEmpty()) throw std::runtime_error("PriorityQueue is empty");
    int minVertex = heap[0].vertex;
    heap[0] = heap[--size];
    heapifyDown(0);
    return minVertex;
}

// בודק אם התור ריק
bool PriorityQueue::isEmpty() const {
    return size == 0;
}

// משנה את העדיפות של קודקוד קיים ומאזן את ה-heap
void PriorityQueue::decreaseKey(int vertex, int newPriority) {
    for (int i = 0; i < size; ++i) {
        if (heap[i].vertex == vertex && heap[i].priority > newPriority) {
            heap[i].priority = newPriority;
            heapifyUp(i);
            return;
        }
    }
}

// בודק אם קודקוד קיים בתור
bool PriorityQueue::contains(int vertex) const {
    for (int i = 0; i < size; ++i) {
        if (heap[i].vertex == vertex)
            return true;
    }
    return false;
}

} 

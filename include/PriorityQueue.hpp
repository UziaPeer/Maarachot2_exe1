// include/PriorityQueue.hpp
// Email: peeruzia@gmail.com
#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP

namespace graph {

// מבנה שמייצג איבר בתור עדיפויות (קודקוד ועדיפות)
struct PQNode {
    int vertex;
    int priority;
};

// תור עדיפויות פשוט על בסיס מערך ו-heap מינימלי
class PriorityQueue {
private:
    PQNode* heap;    // מערך של צמתים (heap)
    int capacity;    // קיבולת מקסימלית של התור
    int size;        // מספר האיברים הקיימים

    // פונקציות פנימיות לשמירה על מבנה ה-heap
    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    // בונה תור עדיפויות עם קיבולת נתונה
    PriorityQueue(int cap);

    // הורס את המערך
    ~PriorityQueue();

    // מוסיף קודקוד עם עדיפות מסוימת
    void insert(int vertex, int priority);

    // מחזיר ומסיר את הקודקוד עם העדיפות הנמוכה ביותר
    int extractMin();

    // בודק אם התור ריק
    bool isEmpty() const;

    // מקטין את העדיפות של קודקוד קיים
    void decreaseKey(int vertex, int newPriority);

    // בודק אם קודקוד קיים בתור
    bool contains(int vertex) const;
};

} 

#endif // PRIORITYQUEUE_HPP


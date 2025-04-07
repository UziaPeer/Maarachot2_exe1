// include/Queue.hpp
// Email: peeruzia@gmail.com
#ifndef QUEUE_HPP
#define QUEUE_HPP

namespace graph {

// מימוש של תור פשוט (עיגולי) ללא STL
class Queue {
private:
    int* data;      // מערך שמחזיק את הערכים
    int front;      // אינדקס ההתחלה של התור
    int rear;       // אינדקס הסוף של התור (לא כולל)
    int size;       // מספר האיברים בתור
    int capacity;   // גודל מקסימלי של התור

public:
    // בונה תור עם קיבולת נתונה
    Queue(int capacity);

    // הורס את המערך
    ~Queue();

    // מוסיף איבר לסוף התור
    void enqueue(int value);

    // מוציא איבר מההתחלה של התור
    int dequeue();

    // בודק אם התור ריק
    bool isEmpty() const;
};

} 

#endif // QUEUE_HPP


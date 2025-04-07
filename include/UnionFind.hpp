// include/UnionFind.hpp
// Email: peeruzia@gmail.com
#ifndef UNIONFIND_HPP
#define UNIONFIND_HPP

namespace graph {

// מבנה נתונים Union-Find (עם איחוד לפי דרגה ודחיסת נתיב)
class UnionFind {
private:
    int* parent;  // מערך שמצביע על ההורה של כל איבר
    int* rank;    // דרגת העץ (עוזר לצמצם גובה)
    int size;     // מספר האיברים הכולל

public:
    // בונה מבנה Union-Find עם n קבוצות נפרדות (כל איבר בקבוצה משלו)
    UnionFind(int n);

    // משחרר זיכרון
    ~UnionFind();

    // מחפש את הנציג (השורש) של הקבוצה ש-x שייך לה
    int find(int x);

    // מחבר את הקבוצות של x ושל y
    void unite(int x, int y);

    // בודק אם x ו-y שייכים לאותה קבוצה
    bool connected(int x, int y);
};

} // namespace graph

#endif // UNIONFIND_HPP

// include/Graph.hpp
// Email: peeruzia@gmail.com
#ifndef GRAPH_HPP
#define GRAPH_HPP

namespace graph {

// מבנה של צומת ברשימת שכנויות (קודקוד יעד, משקל, מצביע לצומת הבא)
struct Node {
    int vertex;
    int weight;
    Node* next;
};

// מחלקת גרף לא מכוונת עם משקלים, לפי רשימת שכנויות
class Graph {
private:
    int numVertices;
    Node** adjList;

public:
 // בונה גרף עם מספר קודקודים נתון (ללא קשתות)
    Graph(int vertices);
// הורס את כל הזיכרון שהוקצה לרשימות
    ~Graph();
    void addEdge(int src, int dest, int weight = 1);
    void removeEdge(int src, int dest);
    void print_graph() const;
    int getNumVertices() const;
// מחזיר את תחילת רשימת השכנים של קודקוד מסוים
    Node* getAdjList(int vertex) const;
};

} 

#endif // GRAPH_HPP

// src/Graph.cpp
// Email: peeruzia@gmail.com
#include "Graph.hpp"
#include <iostream>
#include <stdexcept>

namespace graph {

// בנאי - מקצה זיכרון לגרף עם numVertices קודקודים
Graph::Graph(int vertices) : numVertices(vertices) {
    adjList = new Node*[numVertices];
    for (int i = 0; i < numVertices; ++i) {
        adjList[i] = nullptr; // מתחילים עם רשימות ריקות
    }
}

// דסטרקטור - משחרר את כל הזיכרון של רשימות השכנות
Graph::~Graph() {
    for (int i = 0; i < numVertices; ++i) {
        Node* current = adjList[i];
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] adjList;
}

// מוסיף קשת דו-כיוונית עם משקל בין שני קודקודים (יעד ומקור)
void Graph::addEdge(int src, int dest, int weight) {
     // מוסיפים לקודקוד מקור קודקוד יעד
    Node* newNode = new Node{dest, weight, adjList[src]};
    adjList[src] = newNode;
    // מוסיפים גם הפוך כי הגרף לא מכוון
    newNode = new Node{src, weight, adjList[dest]};
    adjList[dest] = newNode;
}

// מסיר קשת בין קודקוד מקור לקודקוד יעד, זורק שגיאה אם לא קיימת קשת כזו

void Graph::removeEdge(int src, int dest) {
    Node** current = &adjList[src];
    bool found = false;
    
        // מחפשים ומוחקים את הקשת מהמקור ליעד
    while (*current) {
        if ((*current)->vertex == dest) {
            Node* temp = *current;
            *current = (*current)->next;
            delete temp;
            found = true;
            break;
        }
        current = &((*current)->next);
    }

        // מסירים גם את הקשת ההפוכה
    current = &adjList[dest];
    while (*current) {
        if ((*current)->vertex == src) {
            Node* temp = *current;
            *current = (*current)->next;
            delete temp;
            break;
        }
        current = &((*current)->next);
    }

    if (!found) {
        throw std::runtime_error("Edge does not exist");
    }
}

// מדפיס את כל הגרף (רשימת שכנויות של כל קודקוד)
void Graph::print_graph() const {
    for (int i = 0; i < numVertices; ++i) {
        std::cout << i << ": ";
        Node* current = adjList[i];
        while (current) {
            std::cout << "(" << current->vertex << ", w=" << current->weight << ") ";
            current = current->next;
        }
        std::cout << "\n";
    }
}

int Graph::getNumVertices() const {
    return numVertices;
}

// מחזיר את תחילת רשימת השכנים של קודקוד מסוים
Node* Graph::getAdjList(int vertex) const {
    return adjList[vertex];
}

} 

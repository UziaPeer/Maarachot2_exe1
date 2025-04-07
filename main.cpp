// main.cpp
// Email: peeruzia@gmail.com
#include "Graph.hpp"
#include "Algorithms.hpp"
#include <iostream>

using namespace graph;

int main() {
    
    // יוצרים גרף עם 6 קודקודים (0 עד 5) במקרה הזה
    
    Graph g(6);

    // מוסיפים קשתות עם משקלים
    g.addEdge(0, 1, 7);
    g.addEdge(0, 2, 9);
    g.addEdge(0, 5, 14);
    g.addEdge(1, 2, 10);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 11);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, 6);
    g.addEdge(4, 5, 9);

    std::cout << "Original Graph:\n";
    g.print_graph();

     // סריקת BFS מהקודקוד 0

    Graph bfsTree = Algorithms::bfs(g, 0);
    std::cout << "\nBFS Tree from node 0:\n";
    bfsTree.print_graph();

    // סריקת DFS מהקודקוד 0

    Graph dfsTree = Algorithms::dfs(g, 0);
    std::cout << "\nDFS Tree from node 0:\n";
    dfsTree.print_graph();

    // דיאקסטרה למציאת מסלולים קצרים מקודקוד 0

    Graph dijkstraTree = Algorithms::dijkstra(g, 0);
    std::cout << "\nDijkstra Tree from node 0:\n";
    dijkstraTree.print_graph();

    // עץ פורש מינימלי בעזרת Prim

    Graph primTree = Algorithms::prim(g);
    std::cout << "\nPrim MST:\n";
    primTree.print_graph();

    // עץ פורש מינימלי בעזרת Kruskal

    Graph kruskalTree = Algorithms::kruskal(g);
    std::cout << "\nKruskal MST:\n";
    kruskalTree.print_graph();

    return 0;
}

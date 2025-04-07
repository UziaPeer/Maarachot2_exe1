// include/Graph.hpp
// Email: peeruzia@gmail.com
#ifndef GRAPH_HPP
#define GRAPH_HPP

namespace graph {

struct Node {
    int vertex;
    int weight;
    Node* next;
};

class Graph {
private:
    int numVertices;
    Node** adjList;

public:
    Graph(int vertices);
    ~Graph();
    void addEdge(int src, int dest, int weight = 1);
    void removeEdge(int src, int dest);
    void print_graph() const;
    int getNumVertices() const;
    Node* getAdjList(int vertex) const;
};

} // namespace graph

#endif // GRAPH_HPP

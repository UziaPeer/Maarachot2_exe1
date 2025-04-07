// src/Graph.cpp
// Email: peeruzia@gmail.com
#include "Graph.hpp"
#include <iostream>
#include <stdexcept>

namespace graph {

Graph::Graph(int vertices) : numVertices(vertices) {
    adjList = new Node*[numVertices];
    for (int i = 0; i < numVertices; ++i) {
        adjList[i] = nullptr;
    }
}

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

void Graph::addEdge(int src, int dest, int weight) {
    Node* newNode = new Node{dest, weight, adjList[src]};
    adjList[src] = newNode;

    newNode = new Node{src, weight, adjList[dest]};
    adjList[dest] = newNode;
}

void Graph::removeEdge(int src, int dest) {
    Node** current = &adjList[src];
    bool found = false;
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

Node* Graph::getAdjList(int vertex) const {
    return adjList[vertex];
}

} // namespace graph

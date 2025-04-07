// src/Algorithms.cpp
// Email: peeruzia@gmail.com
#include "Algorithms.hpp"
#include "Queue.hpp"
#include "PriorityQueue.hpp"
#include "UnionFind.hpp"
#include <stdexcept>

namespace graph {

Graph Algorithms::bfs(const Graph& g, int start) {
    int n = g.getNumVertices();
    bool* visited = new bool[n];
    for (int i = 0; i < n; ++i) visited[i] = false;

    Graph tree(n);
    Queue q(n);

    visited[start] = true;
    q.enqueue(start);

    while (!q.isEmpty()) {
        int v = q.dequeue();
        Node* curr = g.getAdjList(v);

        while (curr) {
            int u = curr->vertex;
            if (!visited[u]) {
                visited[u] = true;
                tree.addEdge(v, u, curr->weight);
                q.enqueue(u);
            }
            curr = curr->next;
        }
    }

    delete[] visited;
    return tree;
}

void dfsHelper(const Graph& g, int v, bool* visited, Graph& tree) {
    visited[v] = true;
    Node* curr = g.getAdjList(v);
    while (curr) {
        int u = curr->vertex;
        if (!visited[u]) {
            tree.addEdge(v, u, curr->weight);
            dfsHelper(g, u, visited, tree);
        }
        curr = curr->next;
    }
}

Graph Algorithms::dfs(const Graph& g, int start) {
    int n = g.getNumVertices();
    bool* visited = new bool[n];
    for (int i = 0; i < n; ++i) visited[i] = false;

    Graph tree(n);
    dfsHelper(g, start, visited, tree);

    delete[] visited;
    return tree;
}

Graph Algorithms::dijkstra(const Graph& g, int start) {
    int n = g.getNumVertices();
    int* dist = new int[n];
    for (int i = 0; i < n; ++i) dist[i] = 1e9;
    dist[start] = 0;

    Graph tree(n);
    PriorityQueue pq(n);
    pq.insert(start, 0);

    while (!pq.isEmpty()) {
        int v = pq.extractMin();
        Node* curr = g.getAdjList(v);

        while (curr) {
            int u = curr->vertex;
            int weight = curr->weight;
            if (dist[v] + weight < dist[u]) {
                dist[u] = dist[v] + weight;
                tree.addEdge(v, u, weight);
                if (pq.contains(u)) {
                    pq.decreaseKey(u, dist[u]);
                } else {
                    pq.insert(u, dist[u]);
                }
            }
            curr = curr->next;
        }
    }

    delete[] dist;
    return tree;
}

Graph Algorithms::prim(const Graph& g) {
    int n = g.getNumVertices();
    bool* inTree = new bool[n];
    int* key = new int[n];
    int* parent = new int[n];

    for (int i = 0; i < n; ++i) {
        inTree[i] = false;
        key[i] = 1e9;
        parent[i] = -1;
    }

    key[0] = 0;
    PriorityQueue pq(n);
    pq.insert(0, 0);

    while (!pq.isEmpty()) {
        int u = pq.extractMin();
        inTree[u] = true;

        Node* curr = g.getAdjList(u);
        while (curr) {
            int v = curr->vertex;
            int w = curr->weight;
            if (!inTree[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
                if (pq.contains(v)) {
                    pq.decreaseKey(v, w);
                } else {
                    pq.insert(v, w);
                }
            }
            curr = curr->next;
        }
    }

    Graph tree(n);
    for (int v = 1; v < n; ++v) {
        if (parent[v] != -1) {
            tree.addEdge(v, parent[v], key[v]);
        }
    }

    delete[] inTree;
    delete[] key;
    delete[] parent;
    return tree;
}

Graph Algorithms::kruskal(const Graph& g) {
    int n = g.getNumVertices();
    Graph mst(n);
    UnionFind uf(n);

    struct Edge {
        int src, dest, weight;
    };

    Edge* edges = new Edge[n * n];
    int edgeCount = 0;
    bool** added = new bool*[n];
    for (int i = 0; i < n; ++i) {
        added[i] = new bool[n];
        for (int j = 0; j < n; ++j) added[i][j] = false;
    }

    for (int i = 0; i < n; ++i) {
        Node* curr = g.getAdjList(i);
        while (curr) {
            int j = curr->vertex;
            if (!added[i][j] && !added[j][i]) {
                edges[edgeCount++] = {i, j, curr->weight};
                added[i][j] = added[j][i] = true;
            }
            curr = curr->next;
        }
    }

    for (int i = 0; i < edgeCount - 1; ++i) {
        for (int j = i + 1; j < edgeCount; ++j) {
            if (edges[i].weight > edges[j].weight) {
                Edge temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }

    for (int i = 0; i < edgeCount; ++i) {
        int u = edges[i].src;
        int v = edges[i].dest;
        if (!uf.connected(u, v)) {
            uf.unite(u, v);
            mst.addEdge(u, v, edges[i].weight);
        }
    }

    for (int i = 0; i < n; ++i) delete[] added[i];
    delete[] added;
    delete[] edges;

    return mst;
}

} // namespace graph

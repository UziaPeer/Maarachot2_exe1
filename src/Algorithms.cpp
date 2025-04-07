// src/Algorithms.cpp
// Email: peeruzia@gmail.com
#include "Algorithms.hpp"
#include "Queue.hpp"
#include "PriorityQueue.hpp"
#include "UnionFind.hpp"
#include <stdexcept>

namespace graph {

// אלגוריתם BFS - בונה עץ סריקה מהגרף g, החל מהקודקוד start
Graph Algorithms::bfs(const Graph& g, int start) {
    int n = g.getNumVertices();
    bool* visited = new bool[n]{false}; // מערך ביקורים

    Graph tree(n);       // נבנה את עץ הסריקה
    Queue q(n);          // תור פשוט, ללא STL

    visited[start] = true;
    q.enqueue(start);    // מתחילים מהקודקוד הנתון

    while (!q.isEmpty()) {
        int v = q.dequeue();           // מוציאים קודקוד מהתור
        Node* curr = g.getAdjList(v); // משיגים את שכניו

        while (curr) {
            int u = curr->vertex;
            if (!visited[u]) {
                visited[u] = true;
                tree.addEdge(v, u, curr->weight); // מוסיפים לעץ את הקשת
                q.enqueue(u); // מוסיפים שכן לתור להמשך הסריקה
            }
            curr = curr->next;
        }
    }

    delete[] visited;
    return tree;
}

// פונקציית עזר רקורסיבית עבור DFS
void dfsHelper(const Graph& g, int v, bool* visited, Graph& tree) {
    visited[v] = true;

    Node* curr = g.getAdjList(v); // עוברים על כל השכנים של v
    while (curr) {
        int u = curr->vertex;
        if (!visited[u]) {
            tree.addEdge(v, u, curr->weight); // מוסיפים קשת לעץ הסריקה
            dfsHelper(g, u, visited, tree);   // קוראים רקורסיבית
        }
        curr = curr->next;
    }
}

// אלגוריתם DFS - בונה עץ סריקה מהגרף g, החל מ-start
Graph Algorithms::dfs(const Graph& g, int start) {
    int n = g.getNumVertices();
    bool* visited = new bool[n]{false};

    Graph tree(n);
    dfsHelper(g, start, visited, tree);

    delete[] visited;
    return tree;
}

// אלגוריתם Dijkstra - מוצא מסלולים קצרים מ-start לכל שאר הקודקודים
Graph Algorithms::dijkstra(const Graph& g, int start) {
    int n = g.getNumVertices();
    int* dist = new int[n];  // מרחקים מכל קודקוד
    for (int i = 0; i < n; ++i) dist[i] = 1e9;
    dist[start] = 0;

    Graph tree(n);
    PriorityQueue pq(n);     // תור עדיפויות פשוט
    pq.insert(start, 0);

    while (!pq.isEmpty()) {
        int v = pq.extractMin();     // מוציאים את הקודקוד עם המרחק הקצר ביותר
        Node* curr = g.getAdjList(v);

        while (curr) {
            int u = curr->vertex;
            int weight = curr->weight;
            // בודקים אם מצאנו מסלול קצר יותר
            if (dist[v] + weight < dist[u]) {
                dist[u] = dist[v] + weight;
                tree.addEdge(v, u, weight); // מוסיפים קשת לעץ המסלולים
                if (pq.contains(u)) {
                    pq.decreaseKey(u, dist[u]); // מעדכנים עדיפות
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

// אלגוריתם Prim - בונה עץ פורש מינימלי בעזרת תור עדיפויות
Graph Algorithms::prim(const Graph& g) {
    int n = g.getNumVertices();
    bool* inTree = new bool[n]{false}; // האם הקודקוד כבר בעץ
    int* key = new int[n];             // עלות מינימלית להגיע לקודקוד
    int* parent = new int[n];          // מאיזה קודקוד הגענו

    for (int i = 0; i < n; ++i) {
        key[i] = 1e9;
        parent[i] = -1;
    }
    key[0] = 0;

    PriorityQueue pq(n);
    pq.insert(0, 0); // מתחילים מקודקוד 0

    while (!pq.isEmpty()) {
        int u = pq.extractMin(); // קודקוד עם מפתח מינימלי
        inTree[u] = true;

        Node* curr = g.getAdjList(u);
        while (curr) {
            int v = curr->vertex;
            int w = curr->weight;
            // אם v לא בעץ והקשת זולה יותר ממה שיש לנו
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
            tree.addEdge(v, parent[v], key[v]); // בונים את העץ
        }
    }

    delete[] inTree;
    delete[] key;
    delete[] parent;
    return tree;
}

// אלגוריתם Kruskal - מוצא עץ פורש מינימלי בעזרת Union-Find
Graph Algorithms::kruskal(const Graph& g) {
    int n = g.getNumVertices();
    Graph mst(n);
    UnionFind uf(n);

    struct Edge {
        int src, dest, weight;
    };

    Edge* edges = new Edge[n * n]; // נשמור את כל הקשתות
    int edgeCount = 0;

    // טבלת עזר למניעת כפילויות
    bool** added = new bool*[n];
    for (int i = 0; i < n; ++i)
        added[i] = new bool[n]{false};

    // אוספים את כל הקשתות בלי כפילויות
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

    // ממיינים את הקשתות לפי משקל (מיון פשוט)
    for (int i = 0; i < edgeCount - 1; ++i) {
        for (int j = i + 1; j < edgeCount; ++j) {
            if (edges[i].weight > edges[j].weight) {
                Edge temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }

    // בונים את העץ תוך בדיקה שלא יוצרים מעגלים
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

} 


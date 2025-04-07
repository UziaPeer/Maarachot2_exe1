// test/test_graph.cpp
// Email: peeruzia@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Graph.hpp"
#include "Algorithms.hpp"

using namespace graph;

TEST_CASE("Graph - addEdge and removeEdge") {
    Graph g(3);
    g.addEdge(0, 1);
    g.addEdge(1, 2);

    // הקשת קיימת
    CHECK(g.getAdjList(0) != nullptr);
    CHECK(g.getAdjList(1) != nullptr);

    // הסרת קשת קיימת
    g.removeEdge(0, 1);
    Node* curr = g.getAdjList(0);
    while (curr) {
        CHECK(curr->vertex != 1);
        curr = curr->next;
    }

    // הסרת קשת שאינה קיימת אמורה לזרוק חריגה
    CHECK_THROWS(g.removeEdge(0, 2));
}

TEST_CASE("BFS algorithm") {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    Graph bfs_tree = Algorithms::bfs(g, 0);
    CHECK(bfs_tree.getNumVertices() == 5);
    CHECK(bfs_tree.getAdjList(1) != nullptr);
    CHECK(bfs_tree.getAdjList(2) != nullptr);
}

TEST_CASE("DFS algorithm") {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    Graph dfs_tree = Algorithms::dfs(g, 0);
    CHECK(dfs_tree.getNumVertices() == 5);
}

TEST_CASE("Dijkstra algorithm") {
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(0, 2, 4);
    g.addEdge(2, 3, 1);

    Graph dijkstra_tree = Algorithms::dijkstra(g, 0);
    CHECK(dijkstra_tree.getNumVertices() == 4);
    CHECK(dijkstra_tree.getAdjList(3) != nullptr);
}

TEST_CASE("Prim algorithm") {
    Graph g(4);
    g.addEdge(0, 1, 2);
    g.addEdge(1, 2, 3);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 0, 4);

    Graph mst = Algorithms::prim(g);
    CHECK(mst.getNumVertices() == 4);
}

TEST_CASE("Kruskal algorithm") {
    Graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    Graph mst = Algorithms::kruskal(g);
    CHECK(mst.getNumVertices() == 4);
}


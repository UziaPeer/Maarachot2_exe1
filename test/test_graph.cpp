// test/test_graph.cpp
// Email: peeruzia@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Graph.hpp"
#include "Algorithms.hpp"

using namespace graph;

TEST_CASE("Graph basic operations") {
    Graph g(3);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    CHECK_THROWS(g.removeEdge(0, 2));
    g.removeEdge(1, 2);
    g.addEdge(0, 2);
    g.print_graph(); // מדפיס את הגרף לבדיקה ידנית
}

TEST_CASE("BFS and DFS trees") {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    Graph bfs_tree = Algorithms::bfs(g, 0);
    Graph dfs_tree = Algorithms::dfs(g, 0);
    CHECK(bfs_tree.getNumVertices() == 4);
    CHECK(dfs_tree.getNumVertices() == 4);
}

TEST_CASE("Dijkstra on weighted graph") {
    Graph g(3);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(0, 2, 4);
    Graph d = Algorithms::dijkstra(g, 0);
    CHECK(d.getNumVertices() == 3);
}

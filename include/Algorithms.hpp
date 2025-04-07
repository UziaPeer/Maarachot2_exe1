// include/Algorithms.hpp
// Email: peeruzia@gmail.com
#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "Graph.hpp"

namespace graph {

// מחלקה סטטית שמכילה את האלגוריתמים הנדרשים על גרפים
class Algorithms {
public:
    static Graph bfs(const Graph& g, int start);
    static Graph dfs(const Graph& g, int start);
    static Graph dijkstra(const Graph& g, int start);
    static Graph prim(const Graph& g);
    static Graph kruskal(const Graph& g);
};

} 

#endif // ALGORITHMS_HPP

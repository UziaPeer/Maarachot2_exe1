// include/UnionFind.hpp
// Email: peeruzia@gmail.com
#ifndef UNIONFIND_HPP
#define UNIONFIND_HPP

namespace graph {

class UnionFind {
private:
    int* parent;
    int* rank;
    int size;

public:
    UnionFind(int n);
    ~UnionFind();
    int find(int x);
    void unite(int x, int y);
    bool connected(int x, int y);
};

} 

#endif // UNIONFIND_HPP

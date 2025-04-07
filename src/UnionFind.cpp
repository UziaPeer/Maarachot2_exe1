// src/UnionFind.cpp
// Email: peeruzia@gmail.com
#include "UnionFind.hpp"

namespace graph {

// בונה n קבוצות כאשר כל איבר הוא שורש של עצמו (parent[i] = i)

UnionFind::UnionFind(int n) : size(n) {
    parent = new int[n];
    rank = new int[n];
    for (int i = 0; i < n; ++i) {
        parent[i] = i; // כל איבר הוא ההורה של עצמו
        rank[i] = 0;   // דרגת עץ מתחילה מ־0
    }
}

// משחרר את המערכים

UnionFind::~UnionFind() {
    delete[] parent;
    delete[] rank;
}

// מוצא את הנציג של הקבוצה של x, עם דחיסת נתיב 

int UnionFind::find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

// מחבר בין שתי קבוצות לפי דרגה - קבוצה עם דרגה נמוכה מצטרפת לגבוהה

void UnionFind::unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX == rootY) return; // כבר באותה קבוצה

    if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;
    } else if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
    } else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

// בודק אם שני איברים באותה קבוצה

bool UnionFind::connected(int x, int y) {
    return find(x) == find(y);
}

} // namespace graph

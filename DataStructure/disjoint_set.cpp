#ifndef H_disjoint_set
#define H_disjoint_set

#include <bits/stdc++.h>

using namespace std;

class DisjointSet {
 public:
  vector<int> rank, p, size;

  DisjointSet() {}
  DisjointSet(int n) {
    rank.resize(n, 0);
    p.resize(n, 0);
    size.resize(n, 0);
    for (int i = 0; i < n; ++i) init(i);
  }

  void init(int x) {
    p[x] = x;
    rank[x] = 0;
    size[x] = 1;
  }

  bool isSame(int x, int y) { return root(x) == root(y); }

  void makeSet(int x, int y) {
    if (isSame(x, y)) return;
    link(root(x), root(y));
  }

  void link(int x, int y) {
    if (rank[x] > rank[y]) {
      p[y] = x;
      size[x] += size[y];
    } else {
      p[x] = y;
      size[y] += size[x];
      if (rank[x] == rank[y]) {
        rank[y]++;
      }
    }
  }

  int root(int x) {
    if (x != p[x]) {
      p[x] = root(p[x]);
    }
  }

  int getSize(int x) { return size[root(x)]; }
};

#endif

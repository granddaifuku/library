#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A&lang=en"

#include <bits/stdc++.h>

using namespace std;

#include "../../DataStructure/disjoint_set.cpp"

int main() {
  int n, q;
  cin >> n >> q;
  DisjointSet dj = DisjointSet(n);
  for (int i = 0; i < q; ++i) {
    int c, x, y;
    cin >> c >> x >> y;
    if (c) {
      cout << (dj.isSame(x, y) ? 1 : 0) << endl;
    } else {
      dj.makeSet(x, y);
    }
  }

  return 0;
}

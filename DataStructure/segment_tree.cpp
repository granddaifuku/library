#ifndef H_segment_tree
#define H_segment_tree

#include <bits/stdc++.h>

using namespace std;

template <typename T>
class SegmentTree {
 public:
  int n;
  T e;
  vector<T> node;
  function<T(T, T)> operation;
  function<T(T, T)> process;

  SegmentTree() {}
  SegmentTree(int n_, T e_, function<T(T, T)> operation_,
              function<T(T, T)> process_)
      : e(e_), operation(operation_), process(process_) {
    n = 1;
    while (n < n_) n <<= 1;
    node.assign(2 * n, e);
  }

  void build() {
    for (int i = n - 1; i > 0; --i) {
      node[i] = operation(node[i * 2 + 0], node[i * 2 + 1]);
    }
  }

  void set(int idx, T v) { node[idx + n] = process(node[idx + n], v); }

  void update(int idx, T v) {
    idx += n;
    node[idx] = process(node[idx], v);
    while (idx >>= 1) {
      node[idx] = operation(node[idx * 2 + 0], node[idx * 2 + 1]);
    }
  }

  T query(int a, int b) { return query(a, b + 1, 1, 0, n); }

  T query(int a, int b, int k, int l, int r) {
    if (a >= r || b <= l) return e;
    if (a <= l && b >= r) return node[k];
    T c = query(a, b, 2 * k + 0, l, (l + r) / 2);
    T d = query(a, b, 2 * k + 1, (l + r) / 2, r);

    return operation(c, d);
  }

  T operator[](int idx) { return node[idx + n]; }
};

#endif

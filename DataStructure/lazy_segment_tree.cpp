#ifndef H_lazy_segment_tree
#define H_lazy_segment_tree

#include <bits/stdc++.h>

using namespace std;

template <typename T, typename U = T>
class LazySegmentTree {
 public:
  int n;
  T e;
  U oe;
  vector<T> node;
  vector<U> lazy;

  using F = function<T(T, T)>;
  using G = function<T(T, U)>;
  using H = function<U(U, U)>;
  using P = function<U(U, int)>;

  const F f;
  const G g;
  const H h;
  const P p;

  LazySegmentTree() {}
  LazySegmentTree(int n_, const T e_, const U oe_, const F f_, const G g_,
                  const H h_, const P p_)
      : e(e_), oe(oe_), f(f_), g(g_), h(h_), p(p_) {
    n = 1;
    while (n < n_) n <<= 1;
    node.assign(2 * n, e);
    lazy.assign(2 * n, oe);
  }

  void build() {
    for (int i = n - 1; i > 0; --i) {
      node[i] = f(node[i * 2 + 0], node[i * 2 + 1]);
    }
  }

  void set(int idx, T v) { node[idx + n] = v; }

  void eval(int k, int len) {
    if (lazy[k] == oe) return;
    if (k < n) {
      lazy[k * 2 + 0] = h(lazy[k * 2 + 0], lazy[k]);
      lazy[k * 2 + 1] = h(lazy[k * 2 + 1], lazy[k]);
    }
    node[k] = g(node[k], p(lazy[k], len));
    lazy[k] = oe;
  }

  void update(int a, int b, const U x) { update(a, b + 1, x, 1, 0, n); }

  void update(int a, int b, U x, int k, int l, int r) {
    eval(k, r - l);
    if (a <= l && b >= r) {
      lazy[k] = h(lazy[k], x);
      eval(k, r - l);
    } else if (a < r && b > l) {
      update(a, b, x, k * 2 + 0, l, (l + r) >> 1);
      update(a, b, x, k * 2 + 1, (l + r) >> 1, r);
      node[k] = f(node[k * 2 + 0], node[k * 2 + 1]);
    }
  }

  T query(int a, int b) { return query(a, b + 1, 1, 0, n); }

  T query(int a, int b, int k, int l, int r) {
    eval(k, r - l);
    if (a >= r || b <= l) return e;
    if (a <= l && b >= r) return node[k];
    T vl = query(a, b, k * 2 + 0, l, (l + r) >> 1);
    T vr = query(a, b, k * 2 + 1, (l + r) >> 1, r);
    return f(vl, vr);
  }

  T operator[](int idx) { return query(idx, idx + 1); }
};

#endif

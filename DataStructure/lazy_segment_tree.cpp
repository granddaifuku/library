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
  function<T(T, T)> operation;
  function<T(T, U)> apply;
  function<U(U, U)> manage;

  LazySegmentTree() {}
  LazySegmentTree(int n_, T e_, U oe_, function<T(T, T)> operation_, function<T(T, U)> apply_, function<U(U, U)> manage_) :
	e(e_), oe(oe_), operation(operation_), apply(apply_), manage(manage_) {
	n = 1;
	while (n < n_) n <<= 1;
	node.assign(2 * n, e);
	lazy.assign(2 * n, oe);
  }
  
  void build() {
	for (int i = n - 1; i > 0; --i) {
	  node[i] = operation(node[i * 2 + 0], node[i * 2 + 1]);
	}
  }

  void set(int idx, T v) {
	node[idx + n] = v;
  }

  void eval(int k) {
	if (lazy[k] == oe) return;
	if (k < n) {
	  lazy[k * 2 + 0] = manage(lazy[k * 2 + 0], lazy[k]);
	  lazy[k * 2 + 1] = manage(lazy[k * 2 + 1], lazy[k]);
	}
	node[k] = apply(node[k], lazy[k]);
	lazy[k] = oe;
  }

  void update(int a, int b, U x) {
	update(a, b + 1, x, 1, 0, n);
  }

  void update(int a, int b, U x, int k, int l, int r) {
	eval(k);
	if (a <= l && b >= r) {
	  lazy[k] = manage(lazy[k], x);
	  eval(k);
	} else if (a < r && b > l) {
	  update(a, b, x, k * 2 + 0, l, (l + r) / 2);
	  update(a, b, x, k * 2 + 1, (l + r) / 2, r);
	  node[k] = operation(node[k * 2 + 0], node[k * 2 + 1]);
	}
  }

  T query(int a, int b) {
	return query(a, b + 1, 1, 0, n);
  }

  T query(int a, int b, int k, int l, int r) {
	eval(k);
	if (a >= r || b <= l) return e;
	if (a <= l && b >= r) return node[k];
	T vl = query(a, b, k * 2 + 0, l, (l + r) / 2);
	T vr = query(a, b, k * 2 + 1, (l + r) / 2, r);
	return operation(vl, vr);
  }

  T operator[](int idx) {
	return query(idx, idx + 1);
  }
};

#endif  
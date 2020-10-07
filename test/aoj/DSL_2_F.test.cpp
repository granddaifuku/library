#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F"

#include <bits/stdc++.h>

using namespace std;

// #include "../../DataStructure/lazy_segment_tree.cpp"

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

  // void update(int a, int b, U x) {
  // 	evaluate(a += n);
  // 	evaluate(b += n - 1);
  // 	for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
  // 	  if (l & 1) lazy[l] = manage(lazy[l], x), ++l;
  // 	  if (r & 1) --r, lazy[r] = manage(lazy[r], x);
  // 	}
  // 	calc(a);
  // 	calc(b);
  // }

  // T query(int a, int b) {
  // 	evaluate(a += n);
  // 	evaluate(b += n - 1);
  // 	T L = e, R = e;
  // 	for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
  // 	  if (l & 1) L = operation(L, reflect(l++));
  // 	  if (r & 1) R = operation(reflect(--r), R);
  // 	}

  // 	return operation(L, R);
  // }

  // inline void calc(int k) {
  // 	while (k >>= 1) node[k] = operation(reflect(2 * k + 0), reflect(2 * k + 1));
  // }

  // inline void evaluate(int k) {
  // 	for (int i = height; i > 0; --i) propagate(k >> i);
  // }

  // inline void propagate(int k) {
  // 	if (lazy[k] == oe) return;
  // 	lazy[2 * k + 0] = manage(lazy[2 * k + 0], lazy[k]);
  // 	lazy[2 * k + 1] = manage(lazy[2 * k + 1], lazy[k]);
  // 	node[k] = reflect(k);
  // 	lazy[k] = oe;
  // }

  // inline T reflect(int k) {
  // 	return lazy[k] == oe ? node[k] : apply(node[k], lazy[k]);
  // }

  T operator[](int idx) {
	return query(idx, idx + 1);
  }
};

using ll = long long;

const ll INF = 2147483647;

int main() {
  int n, q;
  cin >> n >> q;
  LazySegmentTree<ll> seg = LazySegmentTree<ll>(n, INF, INF, [](ll a, ll b) { return min(a, b); }, 
												  [](ll a, ll b) { return b; }, [](ll a, ll b) { return b; });
  for (int i = 0; i < q; ++i) {
	int type, s, t;
	cin >> type >> s >> t;
	if (type) {
	  cout << seg.query(s, t) << endl;
	} else {
	  ll x;
	  cin >> x;
	  seg.update(s, t, x);
	}
  }  

  return 0;
}

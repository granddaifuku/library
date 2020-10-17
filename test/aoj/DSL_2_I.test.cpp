#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_I"

#include <bits/stdc++.h>

using namespace std;

#include "../../DataStructure/lazy_segment_tree.cpp"

using ll = long long;
const int Inf = 1e9;

int main() {
  int n, q;
  cin >> n >> q;
  using pi = pair<ll, int>;
  LazySegmentTree<pi, int> seg = LazySegmentTree<pi, int>(n, pi(0LL, 0), Inf, [](pi a, pi b) { return pi(a.first + b.first, a.second + b.second); }, [](pi a, int b) { return pi(a.second * b, a.second); }, [](int a, int b) { return b; }, [](int a, int b) { return a; });
  for (int i = 0; i < n; ++i) seg.set(i, pi(0LL, 1));
  seg.build();
  for (int i = 0; i < q; ++i) {
	int c, s, t;
	cin >> c >> s >> t;
	if (c) {
	  cout << seg.query(s, t).first << endl;
	} else {
	  int x;
	  cin >> x;
	  seg.update(s, t, x);
	}
  }

  return 0;
}

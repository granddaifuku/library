#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H&lang=ja"

#include <bits/stdc++.h>

using namespace std;

#include "../../DataStructure/lazy_segment_tree.cpp"

using ll = long long;

const int INF = 1e9;

int main() {
  int n, q;
  cin >> n >> q;
  LazySegmentTree<int> seg = LazySegmentTree<int>(n, INF, 0, [](int a, int b) { return min(a, b); },
												  [](int a, int b) { return a + b; }, [](int a, int b) { return a + b; });
  for (int i = 0; i < n; ++i) seg.set(i, 0);
  seg.build();
  for (int i = 0; i < q; ++i) {
	int c, s, t;
	cin >> c >> s >> t;
	if (c) {
	  cout << seg.query(s, t) << endl;
	} else {
	  int x;
	  cin >> x;
	  seg.update(s, t, x);
	}
  }

  return 0;
}

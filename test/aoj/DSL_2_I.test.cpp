#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_I"

#include <bits/stdc++.h>

using namespace std;

#include "../../DataStructure/lazy_segment_tree.cpp"

int main() {
  int n, q;
  cin >> n >> q;
  LazySegmentTree<int> seg = LazySegmentTree<int>(n, 0, 0, [](int a, int b) { return a + b; }, [](int a, int b) { return b; }, [](int a, int b) { return b; });
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

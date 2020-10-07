#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D"

#include <bits/stdc++.h>

using namespace std;

#include "../../DataStructure/lazy_segment_tree.cpp"

using ll = long long;
const ll INF = 2147483647;

int main() {
  int n, q;
  cin >> n >> q;
  LazySegmentTree<int> seg = LazySegmentTree<int>(n, INF, 0, [](ll a, ll b) { return b; }, 
												  [](ll a, ll b) { return b; }, [](ll a, ll b) { return b; });
  for (int i = 0; i < q; ++i) {
	int t;
	cin >> t;
	if (t) {
	  int idx;
	  cin >> idx;
	  cout << seg[idx] << endl;
	} else {
	  int s, t;
	  ll x;
	  cin >> s >> t >> x;
	  seg.update(s, t, x);
	}
  }
  

  return 0;
}

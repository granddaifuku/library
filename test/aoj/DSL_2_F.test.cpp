#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F"

#include <bits/stdc++.h>

using namespace std;

#include "../../DataStructure/lazy_segment_tree.cpp"

using ll = long long;

const ll INF = 2147483647;

int main() {
  int n, q;
  cin >> n >> q;
  LazySegmentTree<ll> seg = LazySegmentTree<ll>(n, INF, 0LL, [](ll a, ll b) { return min(a, b); }, 
												  [](ll a, ll b) { return b; }, [](ll a, ll b) { return b; });
  for (int i = 0; i < q; ++i) {
	int type, s, t;
	cin >> type >> s >> t;
	if (type) {
	  cout << seg.query(s, t + 1) << endl;
	} else {
	  ll x;
	  cin >> x;
	  seg.update(s, t + 1, x);
	}
  }
  

  return 0;
}

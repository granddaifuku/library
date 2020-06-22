#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"

#include <bits/stdc++.h>

using namespace std;

#include "../../DataStructure/segment_tree.cpp"

const int Inf = 2147483647;

int main() {
    int n, q;
    cin >> n >> q;
    SegmentTree<int> seg = SegmentTree<int>(n, Inf,
        [](int a, int b) { return min(a, b); }, [](int a, int b) { return b; });
    for (int i = 0; i < q; ++i) {
        int c, x, y;
        cin >> c >> x >> y;
        if (c) cout << seg.query(x, y) << endl;
        else seg.update(x, y);
    }

    return 0;
}
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"

#include <bits/stdc++.h>

using namespace std;

#include "../../DataStructure/segment_tree.cpp"

int main() {
    int n, q;
    cin >> n >> q;
    SegmentTree<int> seg = SegmentTree<int>(n, 0,
        [](int a, int b) { return a + b; }, [](int a, int b) { return a + b; });
    for (int i = 0; i < q; ++i) {
        int c, x, y;
        cin >> c >> x >> y;
        if (c) {
            cout << seg.query(x - 1, y - 1) << endl;
        } else {
            seg.update(x - 1, y);
        }
    }

    return 0;
}
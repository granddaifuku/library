#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C&lang=en"

#include <bits/stdc++.h>

using namespace std;

#include "../../Graph/lowest_common_ancestor.cpp"

int main() {
    int n, q;
    cin >> n;
    LCA<int> lca = LCA<int>(n);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int c;
            cin >> c;
            lca.addEdge(i, c);
        }
    }
    lca.init();
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int u, v;
        cin >> u >> v;
        cout << lca.query(u, v) << endl;
    }

    return 0;
}
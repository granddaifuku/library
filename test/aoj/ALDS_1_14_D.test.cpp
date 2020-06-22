#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_D&lang=jp"

#include <bits/stdc++.h>

using namespace std;

#include "../../String/SA_IS.cpp"

int main() {
    string s;
    int q;
    cin >> s >> q;
    SA_IS sa = SA_IS();
    auto v = sa.construct(s);
    for (int i = 0; i < q; ++i) {
        string t;
        cin >> t;
        if (sa.contain(s, t, v)) cout << 1 << endl;
        else cout << 0 << endl;
    }

    return 0;
}
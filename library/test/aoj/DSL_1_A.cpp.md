---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: test/aoj/DSL_1_A.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DSL_1_A.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-22 15:03:42+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A&lang=en">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A&lang=en</a>


## Depends on

* :warning: <a href="../../DataStructure/disjoint_set.cpp.html">DataStructure/disjoint_set.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A&lang=en"

#include <bits/stdc++.h>

using namespace std;

#include "../../DataStructure/disjoint_set.cpp"

int main() {
    int n, q;
    cin >> n >> q;
    DisjointSet dj = DisjointSet(n);
    for (int i = 0; i < q; ++i) {
        int c, x, y;
        cin >> c >> x >> y;
        if (c) {
            cout << (dj.isSame(x, y) ? 1 : 0) << endl;
        } else {
            dj.makeSet(x, y);
        }
    }

    return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DSL_1_A.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A&lang=en"

#include <bits/stdc++.h>

using namespace std;

#line 1 "DataStructure/disjoint_set.cpp"



#line 5 "DataStructure/disjoint_set.cpp"

using namespace std;

class DisjointSet {
    public:
        vector<int> rank, p, size;

        DisjointSet() {}
        DisjointSet(int n) {
            rank.resize(n, 0);
            p.resize(n, 0);
            size.resize(n, 0);
            for (int i = 0; i < n; ++i) init(i);
        }

        void init(int x) {
            p[x] = x;
            rank[x] = 0;
            size[x] = 1;
        }

        bool isSame(int x, int y) {
            return root(x) == root(y);
        }

        void makeSet(int x, int y) {
            if (isSame(x, y)) return;
            link(root(x), root(y));
        }

        void link(int x, int y) {
            if (rank[x] > rank[y]) {
                p[y] = x;
                size[x] += size[y];
            } else {
                p[x] = y;
                size[y] += size[x];
                if (rank[x] == rank[y]) {
                    rank[y]++;
                }
            }
        }

        int root(int x) {
            if (x != p[x]) {
                p[x] = root(p[x]);
            }
            return p[x];
        }

        int getSize(int x) {
            return size[root(x)];
        }
};


#line 8 "test/aoj/DSL_1_A.cpp"

int main() {
    int n, q;
    cin >> n >> q;
    DisjointSet dj = DisjointSet(n);
    for (int i = 0; i < q; ++i) {
        int c, x, y;
        cin >> c >> x >> y;
        if (c) {
            cout << (dj.isSame(x, y) ? 1 : 0) << endl;
        } else {
            dj.makeSet(x, y);
        }
    }

    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>


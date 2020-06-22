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
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: DataStructure/disjoint_set.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e248f107086635fddcead5bf28943fc">DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/disjoint_set.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-22 15:39:22+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_A.test.cpp.html">test/aoj/DSL_2_A.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef H_disjoint_set
#define H_disjoint_set

#include <bits/stdc++.h>

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

#endif
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/disjoint_set.cpp"



#include <bits/stdc++.h>

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



```
{% endraw %}

<a href="../../index.html">Back to top page</a>


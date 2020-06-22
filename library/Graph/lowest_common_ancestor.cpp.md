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


# :heavy_check_mark: Graph/lowest_common_ancestor.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#4cdbd2bafa8193091ba09509cedf94fd">Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/Graph/lowest_common_ancestor.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-22 15:03:42+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_5_C.test.cpp.html">test/aoj/GRL_5_C.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef H_lowest_common_ancestor
#define H_lowest_common_ancestor

#include <bits/stdc++.h>

using namespace std;

template <typename T>
class LCA {
    public:
        int n, log_v = 0;
        vector<int> depth;
        vector<T> costs;
        vector<vector<int> > to;
        vector<vector<T> > cost;
        vector<vector<int> > parent;

        LCA() {}
        LCA(int n_): n(n_) {
            while ((1 << log_v) < n) ++log_v;
            depth.assign(n, 0);
            costs.assign(n, 0);
            to = vector<vector<int> >(n);
            cost = vector<vector<T> >(n);
            parent = vector<vector<int> >(log_v, vector<int>(n, 0));
        }

        void init(int root = 0) {
            dfs(root);
            for (int i = 0; i < log_v - 1; ++i) {
                for (int j = 0; j < n; ++j) parent[i + 1][j] = parent[i][parent[i][j]];
            }
        }

        void addEdge(int u, int v, T c = 0) {
            to[u].push_back(v);
            to[v].push_back(u);
            cost[u].push_back(c);
            cost[v].push_back(c);
        }

        void dfs(int v, int p = -1, int d = 0, T c = 0) {
            if (p != -1) parent[0][v] = p;
            depth[v] = d;
            costs[v] = c;
            for (int i = 0; i < to[v].size(); ++i) {
                int e = to[v][i];
                if (e == p) continue;
                dfs(e, v, d + 1, c + cost[v][i]);
            }
        }

        int query(int u, int v) {
            if (depth[u] > depth[v]) swap(u, v);
            for (int i = 0; i < log_v; ++i) {
                if ((depth[v] - depth[u]) >> i & 1) v = parent[i][v];
            }
            if (u == v) return u;
            for (int i = log_v - 1; i >= 0; --i) {
                if (parent[i][u] != parent[i][v]) {
                    u = parent[i][u];
                    v = parent[i][v];
                }
            }
            return parent[0][u];
        }

        int length(int u, int v) {
            return depth[u] + depth[v] - 2 * depth[query(u, v)];
        }

        T dist(int u, int v) {
            return costs[u] + costs[v] - 2 * costs[query(u, v)];
        }

        // is x on the path u - v
        bool isOnPath(int u, int v, int x) {
            return length(u, x) + length(v, x) == length(u, v);
        }
};

#endif
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Graph/lowest_common_ancestor.cpp"



#include <bits/stdc++.h>

using namespace std;

template <typename T>
class LCA {
    public:
        int n, log_v = 0;
        vector<int> depth;
        vector<T> costs;
        vector<vector<int> > to;
        vector<vector<T> > cost;
        vector<vector<int> > parent;

        LCA() {}
        LCA(int n_): n(n_) {
            while ((1 << log_v) < n) ++log_v;
            depth.assign(n, 0);
            costs.assign(n, 0);
            to = vector<vector<int> >(n);
            cost = vector<vector<T> >(n);
            parent = vector<vector<int> >(log_v, vector<int>(n, 0));
        }

        void init(int root = 0) {
            dfs(root);
            for (int i = 0; i < log_v - 1; ++i) {
                for (int j = 0; j < n; ++j) parent[i + 1][j] = parent[i][parent[i][j]];
            }
        }

        void addEdge(int u, int v, T c = 0) {
            to[u].push_back(v);
            to[v].push_back(u);
            cost[u].push_back(c);
            cost[v].push_back(c);
        }

        void dfs(int v, int p = -1, int d = 0, T c = 0) {
            if (p != -1) parent[0][v] = p;
            depth[v] = d;
            costs[v] = c;
            for (int i = 0; i < to[v].size(); ++i) {
                int e = to[v][i];
                if (e == p) continue;
                dfs(e, v, d + 1, c + cost[v][i]);
            }
        }

        int query(int u, int v) {
            if (depth[u] > depth[v]) swap(u, v);
            for (int i = 0; i < log_v; ++i) {
                if ((depth[v] - depth[u]) >> i & 1) v = parent[i][v];
            }
            if (u == v) return u;
            for (int i = log_v - 1; i >= 0; --i) {
                if (parent[i][u] != parent[i][v]) {
                    u = parent[i][u];
                    v = parent[i][v];
                }
            }
            return parent[0][u];
        }

        int length(int u, int v) {
            return depth[u] + depth[v] - 2 * depth[query(u, v)];
        }

        T dist(int u, int v) {
            return costs[u] + costs[v] - 2 * costs[query(u, v)];
        }

        // is x on the path u - v
        bool isOnPath(int u, int v, int x) {
            return length(u, x) + length(v, x) == length(u, v);
        }
};



```
{% endraw %}

<a href="../../index.html">Back to top page</a>


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


# :heavy_check_mark: test/aoj/GRL_5_C.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_5_C.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-22 15:03:42+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C&lang=en">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C&lang=en</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/Graph/lowest_common_ancestor.cpp.html">Graph/lowest_common_ancestor.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/GRL_5_C.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C&lang=en"

#include <bits/stdc++.h>

using namespace std;

#line 1 "Graph/lowest_common_ancestor.cpp"



#line 5 "Graph/lowest_common_ancestor.cpp"

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


#line 8 "test/aoj/GRL_5_C.test.cpp"

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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>


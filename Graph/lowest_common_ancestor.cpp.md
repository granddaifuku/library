---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_C.test.cpp
    title: test/aoj/GRL_5_C.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/lowest_common_ancestor.cpp\"\n\n\n\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\ntemplate <typename T>\nclass LCA {\n    public:\n  \
    \      int n, log_v = 0;\n        vector<int> depth;\n        vector<T> costs;\n\
    \        vector<vector<int> > to;\n        vector<vector<T> > cost;\n        vector<vector<int>\
    \ > parent;\n\n        LCA() {}\n        LCA(int n_): n(n_) {\n            while\
    \ ((1 << log_v) < n) ++log_v;\n            depth.assign(n, 0);\n            costs.assign(n,\
    \ 0);\n            to = vector<vector<int> >(n);\n            cost = vector<vector<T>\
    \ >(n);\n            parent = vector<vector<int> >(log_v, vector<int>(n, 0));\n\
    \        }\n\n        void init(int root = 0) {\n            dfs(root);\n    \
    \        for (int i = 0; i < log_v - 1; ++i) {\n                for (int j = 0;\
    \ j < n; ++j) parent[i + 1][j] = parent[i][parent[i][j]];\n            }\n   \
    \     }\n\n        void addEdge(int u, int v, T c = 0) {\n            to[u].push_back(v);\n\
    \            to[v].push_back(u);\n            cost[u].push_back(c);\n        \
    \    cost[v].push_back(c);\n        }\n\n        void dfs(int v, int p = -1, int\
    \ d = 0, T c = 0) {\n            if (p != -1) parent[0][v] = p;\n            depth[v]\
    \ = d;\n            costs[v] = c;\n            for (int i = 0; i < to[v].size();\
    \ ++i) {\n                int e = to[v][i];\n                if (e == p) continue;\n\
    \                dfs(e, v, d + 1, c + cost[v][i]);\n            }\n        }\n\
    \n        int query(int u, int v) {\n            if (depth[u] > depth[v]) swap(u,\
    \ v);\n            for (int i = 0; i < log_v; ++i) {\n                if ((depth[v]\
    \ - depth[u]) >> i & 1) v = parent[i][v];\n            }\n            if (u ==\
    \ v) return u;\n            for (int i = log_v - 1; i >= 0; --i) {\n         \
    \       if (parent[i][u] != parent[i][v]) {\n                    u = parent[i][u];\n\
    \                    v = parent[i][v];\n                }\n            }\n   \
    \         return parent[0][u];\n        }\n\n        int length(int u, int v)\
    \ {\n            return depth[u] + depth[v] - 2 * depth[query(u, v)];\n      \
    \  }\n\n        T dist(int u, int v) {\n            return costs[u] + costs[v]\
    \ - 2 * costs[query(u, v)];\n        }\n\n        // is x on the path u - v\n\
    \        bool isOnPath(int u, int v, int x) {\n            return length(u, x)\
    \ + length(v, x) == length(u, v);\n        }\n};\n\n\n"
  code: "#ifndef H_lowest_common_ancestor\n#define H_lowest_common_ancestor\n\n#include\
    \ <bits/stdc++.h>\n\nusing namespace std;\n\ntemplate <typename T>\nclass LCA\
    \ {\n    public:\n        int n, log_v = 0;\n        vector<int> depth;\n    \
    \    vector<T> costs;\n        vector<vector<int> > to;\n        vector<vector<T>\
    \ > cost;\n        vector<vector<int> > parent;\n\n        LCA() {}\n        LCA(int\
    \ n_): n(n_) {\n            while ((1 << log_v) < n) ++log_v;\n            depth.assign(n,\
    \ 0);\n            costs.assign(n, 0);\n            to = vector<vector<int> >(n);\n\
    \            cost = vector<vector<T> >(n);\n            parent = vector<vector<int>\
    \ >(log_v, vector<int>(n, 0));\n        }\n\n        void init(int root = 0) {\n\
    \            dfs(root);\n            for (int i = 0; i < log_v - 1; ++i) {\n \
    \               for (int j = 0; j < n; ++j) parent[i + 1][j] = parent[i][parent[i][j]];\n\
    \            }\n        }\n\n        void addEdge(int u, int v, T c = 0) {\n \
    \           to[u].push_back(v);\n            to[v].push_back(u);\n           \
    \ cost[u].push_back(c);\n            cost[v].push_back(c);\n        }\n\n    \
    \    void dfs(int v, int p = -1, int d = 0, T c = 0) {\n            if (p != -1)\
    \ parent[0][v] = p;\n            depth[v] = d;\n            costs[v] = c;\n  \
    \          for (int i = 0; i < to[v].size(); ++i) {\n                int e = to[v][i];\n\
    \                if (e == p) continue;\n                dfs(e, v, d + 1, c + cost[v][i]);\n\
    \            }\n        }\n\n        int query(int u, int v) {\n            if\
    \ (depth[u] > depth[v]) swap(u, v);\n            for (int i = 0; i < log_v; ++i)\
    \ {\n                if ((depth[v] - depth[u]) >> i & 1) v = parent[i][v];\n \
    \           }\n            if (u == v) return u;\n            for (int i = log_v\
    \ - 1; i >= 0; --i) {\n                if (parent[i][u] != parent[i][v]) {\n \
    \                   u = parent[i][u];\n                    v = parent[i][v];\n\
    \                }\n            }\n            return parent[0][u];\n        }\n\
    \n        int length(int u, int v) {\n            return depth[u] + depth[v] -\
    \ 2 * depth[query(u, v)];\n        }\n\n        T dist(int u, int v) {\n     \
    \       return costs[u] + costs[v] - 2 * costs[query(u, v)];\n        }\n\n  \
    \      // is x on the path u - v\n        bool isOnPath(int u, int v, int x) {\n\
    \            return length(u, x) + length(v, x) == length(u, v);\n        }\n\
    };\n\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: Graph/lowest_common_ancestor.cpp
  requiredBy: []
  timestamp: '2020-06-22 15:03:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_5_C.test.cpp
documentation_of: Graph/lowest_common_ancestor.cpp
layout: document
redirect_from:
- /library/Graph/lowest_common_ancestor.cpp
- /library/Graph/lowest_common_ancestor.cpp.html
title: Graph/lowest_common_ancestor.cpp
---

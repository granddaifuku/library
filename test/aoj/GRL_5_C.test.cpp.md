---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/lowest_common_ancestor.cpp
    title: Graph/lowest_common_ancestor.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C&lang=en
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C&lang=en
  bundledCode: "#line 1 \"test/aoj/GRL_5_C.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C&lang=en\"\
    \n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\n#line 1 \"Graph/lowest_common_ancestor.cpp\"\
    \n\n\n\n#line 5 \"Graph/lowest_common_ancestor.cpp\"\n\nusing namespace std;\n\
    \ntemplate <typename T>\nclass LCA {\n    public:\n        int n, log_v = 0;\n\
    \        vector<int> depth;\n        vector<T> costs;\n        vector<vector<int>\
    \ > to;\n        vector<vector<T> > cost;\n        vector<vector<int> > parent;\n\
    \n        LCA() {}\n        LCA(int n_): n(n_) {\n            while ((1 << log_v)\
    \ < n) ++log_v;\n            depth.assign(n, 0);\n            costs.assign(n,\
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
    \ + length(v, x) == length(u, v);\n        }\n};\n\n\n#line 8 \"test/aoj/GRL_5_C.test.cpp\"\
    \n\nint main() {\n    int n, q;\n    cin >> n;\n    LCA<int> lca = LCA<int>(n);\n\
    \    for (int i = 0; i < n; ++i) {\n        int k;\n        cin >> k;\n      \
    \  for (int j = 0; j < k; ++j) {\n            int c;\n            cin >> c;\n\
    \            lca.addEdge(i, c);\n        }\n    }\n    lca.init();\n    cin >>\
    \ q;\n    for (int i = 0; i < q; ++i) {\n        int u, v;\n        cin >> u >>\
    \ v;\n        cout << lca.query(u, v) << endl;\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C&lang=en\"\
    \n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\n#include \"../../Graph/lowest_common_ancestor.cpp\"\
    \n\nint main() {\n    int n, q;\n    cin >> n;\n    LCA<int> lca = LCA<int>(n);\n\
    \    for (int i = 0; i < n; ++i) {\n        int k;\n        cin >> k;\n      \
    \  for (int j = 0; j < k; ++j) {\n            int c;\n            cin >> c;\n\
    \            lca.addEdge(i, c);\n        }\n    }\n    lca.init();\n    cin >>\
    \ q;\n    for (int i = 0; i < q; ++i) {\n        int u, v;\n        cin >> u >>\
    \ v;\n        cout << lca.query(u, v) << endl;\n    }\n\n    return 0;\n}"
  dependsOn:
  - Graph/lowest_common_ancestor.cpp
  isVerificationFile: true
  path: test/aoj/GRL_5_C.test.cpp
  requiredBy: []
  timestamp: '2020-06-22 15:03:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_5_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_5_C.test.cpp
- /verify/test/aoj/GRL_5_C.test.cpp.html
title: test/aoj/GRL_5_C.test.cpp
---

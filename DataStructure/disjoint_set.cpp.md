---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DSL_1_A.test.cpp
    title: test/aoj/DSL_1_A.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/disjoint_set.cpp\"\n\n\n\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\nclass DisjointSet {\n public:\n  vector<int> rank, p,\
    \ size;\n\n  DisjointSet() {}\n  DisjointSet(int n) {\n    rank.resize(n, 0);\n\
    \    p.resize(n, 0);\n    size.resize(n, 0);\n    for (int i = 0; i < n; ++i)\
    \ init(i);\n  }\n\n  void init(int x) {\n    p[x] = x;\n    rank[x] = 0;\n   \
    \ size[x] = 1;\n  }\n\n  bool isSame(int x, int y) { return root(x) == root(y);\
    \ }\n\n  void makeSet(int x, int y) {\n    if (isSame(x, y)) return;\n    link(root(x),\
    \ root(y));\n  }\n\n  void link(int x, int y) {\n    if (rank[x] > rank[y]) {\n\
    \      p[y] = x;\n      size[x] += size[y];\n    } else {\n      p[x] = y;\n \
    \     size[y] += size[x];\n      if (rank[x] == rank[y]) {\n        rank[y]++;\n\
    \      }\n    }\n  }\n\n  int root(int x) {\n    if (x != p[x]) {\n      p[x]\
    \ = root(p[x]);\n    }\n  }\n\n  int getSize(int x) { return size[root(x)]; }\n\
    };\n\n\n"
  code: "#ifndef H_disjoint_set\n#define H_disjoint_set\n\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\nclass DisjointSet {\n public:\n  vector<int> rank, p,\
    \ size;\n\n  DisjointSet() {}\n  DisjointSet(int n) {\n    rank.resize(n, 0);\n\
    \    p.resize(n, 0);\n    size.resize(n, 0);\n    for (int i = 0; i < n; ++i)\
    \ init(i);\n  }\n\n  void init(int x) {\n    p[x] = x;\n    rank[x] = 0;\n   \
    \ size[x] = 1;\n  }\n\n  bool isSame(int x, int y) { return root(x) == root(y);\
    \ }\n\n  void makeSet(int x, int y) {\n    if (isSame(x, y)) return;\n    link(root(x),\
    \ root(y));\n  }\n\n  void link(int x, int y) {\n    if (rank[x] > rank[y]) {\n\
    \      p[y] = x;\n      size[x] += size[y];\n    } else {\n      p[x] = y;\n \
    \     size[y] += size[x];\n      if (rank[x] == rank[y]) {\n        rank[y]++;\n\
    \      }\n    }\n  }\n\n  int root(int x) {\n    if (x != p[x]) {\n      p[x]\
    \ = root(p[x]);\n    }\n  }\n\n  int getSize(int x) { return size[root(x)]; }\n\
    };\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/disjoint_set.cpp
  requiredBy: []
  timestamp: '2021-09-04 15:28:55+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/DSL_1_A.test.cpp
documentation_of: DataStructure/disjoint_set.cpp
layout: document
redirect_from:
- /library/DataStructure/disjoint_set.cpp
- /library/DataStructure/disjoint_set.cpp.html
title: DataStructure/disjoint_set.cpp
---

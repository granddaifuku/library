---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/disjoint_set.cpp
    title: DataStructure/disjoint_set.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A&lang=en
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A&lang=en
  bundledCode: "#line 1 \"test/aoj/DSL_1_A.test.cpp\"\n#define PROBLEM \\\n  \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A&lang=en\"\
    \n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\n#line 1 \"DataStructure/disjoint_set.cpp\"\
    \n\n\n\n#line 5 \"DataStructure/disjoint_set.cpp\"\n\nusing namespace std;\n\n\
    class DisjointSet {\n public:\n  vector<int> rank, p, size;\n\n  DisjointSet()\
    \ {}\n  DisjointSet(int n) {\n    rank.resize(n, 0);\n    p.resize(n, 0);\n  \
    \  size.resize(n, 0);\n    for (int i = 0; i < n; ++i) init(i);\n  }\n\n  void\
    \ init(int x) {\n    p[x] = x;\n    rank[x] = 0;\n    size[x] = 1;\n  }\n\n  bool\
    \ isSame(int x, int y) { return root(x) == root(y); }\n\n  void makeSet(int x,\
    \ int y) {\n    if (isSame(x, y)) return;\n    link(root(x), root(y));\n  }\n\n\
    \  void link(int x, int y) {\n    if (rank[x] > rank[y]) {\n      p[y] = x;\n\
    \      size[x] += size[y];\n    } else {\n      p[x] = y;\n      size[y] += size[x];\n\
    \      if (rank[x] == rank[y]) {\n        rank[y]++;\n      }\n    }\n  }\n\n\
    \  int root(int x) {\n    if (x != p[x]) {\n      p[x] = root(p[x]);\n    }\n\
    \    return p[x];\n  }\n\n  int getSize(int x) { return size[root(x)]; }\n};\n\
    \n\n#line 9 \"test/aoj/DSL_1_A.test.cpp\"\n\nint main() {\n  int n, q;\n  cin\
    \ >> n >> q;\n  DisjointSet dj = DisjointSet(n);\n  for (int i = 0; i < q; ++i)\
    \ {\n    int c, x, y;\n    cin >> c >> x >> y;\n    if (c) {\n      cout << (dj.isSame(x,\
    \ y) ? 1 : 0) << endl;\n    } else {\n      dj.makeSet(x, y);\n    }\n  }\n\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \\\n  \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A&lang=en\"\
    \n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\n#include \"../../DataStructure/disjoint_set.cpp\"\
    \n\nint main() {\n  int n, q;\n  cin >> n >> q;\n  DisjointSet dj = DisjointSet(n);\n\
    \  for (int i = 0; i < q; ++i) {\n    int c, x, y;\n    cin >> c >> x >> y;\n\
    \    if (c) {\n      cout << (dj.isSame(x, y) ? 1 : 0) << endl;\n    } else {\n\
    \      dj.makeSet(x, y);\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - DataStructure/disjoint_set.cpp
  isVerificationFile: true
  path: test/aoj/DSL_1_A.test.cpp
  requiredBy: []
  timestamp: '2021-09-12 11:32:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_1_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_1_A.test.cpp
- /verify/test/aoj/DSL_1_A.test.cpp.html
title: test/aoj/DSL_1_A.test.cpp
---

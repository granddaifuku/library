---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/segment_tree.cpp
    title: DataStructure/segment_tree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
  bundledCode: "#line 1 \"test/aoj/DSL_2_B.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\n#line 1 \"DataStructure/segment_tree.cpp\"\
    \n\n\n\n#line 5 \"DataStructure/segment_tree.cpp\"\n\nusing namespace std;\n\n\
    template <typename T>\nclass SegmentTree {\n public:\n  int n;\n  T e;\n  vector<T>\
    \ node;\n  function<T(T, T)> operation;\n  function<T(T, T)> process;\n\n  SegmentTree()\
    \ {}\n  SegmentTree(int n_, T e_, function<T(T, T)> operation_,\n            \
    \  function<T(T, T)> process_)\n      : e(e_), operation(operation_), process(process_)\
    \ {\n    n = 1;\n    while (n < n_) n <<= 1;\n    node.assign(2 * n, e);\n  }\n\
    \n  void build() {\n    for (int i = n - 1; i > 0; --i) {\n      node[i] = operation(node[i\
    \ * 2 + 0], node[i * 2 + 1]);\n    }\n  }\n\n  void set(int idx, T v) { node[idx\
    \ + n] = process(node[idx + n], v); }\n\n  void update(int idx, T v) {\n    idx\
    \ += n;\n    node[idx] = process(node[idx], v);\n    while (idx >>= 1) {\n   \
    \   node[idx] = operation(node[idx * 2 + 0], node[idx * 2 + 1]);\n    }\n  }\n\
    \n  T query(int a, int b) { return query(a, b + 1, 1, 0, n); }\n\n  T query(int\
    \ a, int b, int k, int l, int r) {\n    if (a >= r || b <= l) return e;\n    if\
    \ (a <= l && b >= r) return node[k];\n    T c = query(a, b, 2 * k + 0, l, (l +\
    \ r) / 2);\n    T d = query(a, b, 2 * k + 1, (l + r) / 2, r);\n\n    return operation(c,\
    \ d);\n  }\n\n  T operator[](int idx) { return node[idx + n]; }\n};\n\n\n#line\
    \ 8 \"test/aoj/DSL_2_B.test.cpp\"\n\nint main() {\n    int n, q;\n    cin >> n\
    \ >> q;\n    SegmentTree<int> seg = SegmentTree<int>(n, 0,\n        [](int a,\
    \ int b) { return a + b; }, [](int a, int b) { return a + b; });\n    for (int\
    \ i = 0; i < q; ++i) {\n        int c, x, y;\n        cin >> c >> x >> y;\n  \
    \      if (c) {\n            cout << seg.query(x - 1, y - 1) << endl;\n      \
    \  } else {\n            seg.update(x - 1, y);\n        }\n    }\n\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\n#include \"../../DataStructure/segment_tree.cpp\"\
    \n\nint main() {\n    int n, q;\n    cin >> n >> q;\n    SegmentTree<int> seg\
    \ = SegmentTree<int>(n, 0,\n        [](int a, int b) { return a + b; }, [](int\
    \ a, int b) { return a + b; });\n    for (int i = 0; i < q; ++i) {\n        int\
    \ c, x, y;\n        cin >> c >> x >> y;\n        if (c) {\n            cout <<\
    \ seg.query(x - 1, y - 1) << endl;\n        } else {\n            seg.update(x\
    \ - 1, y);\n        }\n    }\n\n    return 0;\n}"
  dependsOn:
  - DataStructure/segment_tree.cpp
  isVerificationFile: true
  path: test/aoj/DSL_2_B.test.cpp
  requiredBy: []
  timestamp: '2021-09-04 15:28:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_B.test.cpp
- /verify/test/aoj/DSL_2_B.test.cpp.html
title: test/aoj/DSL_2_B.test.cpp
---

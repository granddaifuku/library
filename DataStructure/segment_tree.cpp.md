---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_A.test.cpp
    title: test/aoj/DSL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_B.test.cpp
    title: test/aoj/DSL_2_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/segment_tree.cpp\"\n\n\n\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\ntemplate <typename T>\nclass SegmentTree {\n public:\n\
    \  int n;\n  T e;\n  vector<T> node;\n  function<T(T, T)> operation;\n  function<T(T,\
    \ T)> process;\n\n  SegmentTree() {}\n  SegmentTree(int n_, T e_, function<T(T,\
    \ T)> operation_,\n              function<T(T, T)> process_)\n      : e(e_), operation(operation_),\
    \ process(process_) {\n    n = 1;\n    while (n < n_) n <<= 1;\n    node.assign(2\
    \ * n, e);\n  }\n\n  void build() {\n    for (int i = n - 1; i > 0; --i) {\n \
    \     node[i] = operation(node[i * 2 + 0], node[i * 2 + 1]);\n    }\n  }\n\n \
    \ void set(int idx, T v) { node[idx + n] = process(node[idx + n], v); }\n\n  void\
    \ update(int idx, T v) {\n    idx += n;\n    node[idx] = process(node[idx], v);\n\
    \    while (idx >>= 1) {\n      node[idx] = operation(node[idx * 2 + 0], node[idx\
    \ * 2 + 1]);\n    }\n  }\n\n  T query(int a, int b) { return query(a, b + 1, 1,\
    \ 0, n); }\n\n  T query(int a, int b, int k, int l, int r) {\n    if (a >= r ||\
    \ b <= l) return e;\n    if (a <= l && b >= r) return node[k];\n    T c = query(a,\
    \ b, 2 * k + 0, l, (l + r) / 2);\n    T d = query(a, b, 2 * k + 1, (l + r) / 2,\
    \ r);\n\n    return operation(c, d);\n  }\n\n  T operator[](int idx) { return\
    \ node[idx + n]; }\n};\n\n\n"
  code: "#ifndef H_segment_tree\n#define H_segment_tree\n\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\ntemplate <typename T>\nclass SegmentTree {\n public:\n\
    \  int n;\n  T e;\n  vector<T> node;\n  function<T(T, T)> operation;\n  function<T(T,\
    \ T)> process;\n\n  SegmentTree() {}\n  SegmentTree(int n_, T e_, function<T(T,\
    \ T)> operation_,\n              function<T(T, T)> process_)\n      : e(e_), operation(operation_),\
    \ process(process_) {\n    n = 1;\n    while (n < n_) n <<= 1;\n    node.assign(2\
    \ * n, e);\n  }\n\n  void build() {\n    for (int i = n - 1; i > 0; --i) {\n \
    \     node[i] = operation(node[i * 2 + 0], node[i * 2 + 1]);\n    }\n  }\n\n \
    \ void set(int idx, T v) { node[idx + n] = process(node[idx + n], v); }\n\n  void\
    \ update(int idx, T v) {\n    idx += n;\n    node[idx] = process(node[idx], v);\n\
    \    while (idx >>= 1) {\n      node[idx] = operation(node[idx * 2 + 0], node[idx\
    \ * 2 + 1]);\n    }\n  }\n\n  T query(int a, int b) { return query(a, b + 1, 1,\
    \ 0, n); }\n\n  T query(int a, int b, int k, int l, int r) {\n    if (a >= r ||\
    \ b <= l) return e;\n    if (a <= l && b >= r) return node[k];\n    T c = query(a,\
    \ b, 2 * k + 0, l, (l + r) / 2);\n    T d = query(a, b, 2 * k + 1, (l + r) / 2,\
    \ r);\n\n    return operation(c, d);\n  }\n\n  T operator[](int idx) { return\
    \ node[idx + n]; }\n};\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/segment_tree.cpp
  requiredBy: []
  timestamp: '2021-09-04 15:28:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_B.test.cpp
  - test/aoj/DSL_2_A.test.cpp
documentation_of: DataStructure/segment_tree.cpp
layout: document
redirect_from:
- /library/DataStructure/segment_tree.cpp
- /library/DataStructure/segment_tree.cpp.html
title: DataStructure/segment_tree.cpp
---

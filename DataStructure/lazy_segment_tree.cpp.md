---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_F.test.cpp
    title: test/aoj/DSL_2_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_H.test.cpp
    title: test/aoj/DSL_2_H.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_I.test.cpp
    title: test/aoj/DSL_2_I.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/lazy_segment_tree.cpp\"\n\n\n\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\ntemplate <typename T, typename U = T>\nclass LazySegmentTree\
    \ {\n public:\n  int n;\n  T e;\n  U oe;\n  vector<T> node;\n  vector<U> lazy;\n\
    \n  using F = function<T(T, T)>;\n  using G = function<T(T, U)>;\n  using H =\
    \ function<U(U, U)>;\n  using P = function<U(U, int)>;\n\n  const F f;\n  const\
    \ G g;\n  const H h;\n  const P p;\n\n  LazySegmentTree() {}\n  LazySegmentTree(int\
    \ n_, const T e_, const U oe_, const F f_, const G g_,\n                  const\
    \ H h_, const P p_)\n      : e(e_), oe(oe_), f(f_), g(g_), h(h_), p(p_) {\n  \
    \  n = 1;\n    while (n < n_) n <<= 1;\n    node.assign(2 * n, e);\n    lazy.assign(2\
    \ * n, oe);\n  }\n\n  void build() {\n    for (int i = n - 1; i > 0; --i) {\n\
    \      node[i] = f(node[i * 2 + 0], node[i * 2 + 1]);\n    }\n  }\n\n  void set(int\
    \ idx, T v) { node[idx + n] = v; }\n\n  void eval(int k, int len) {\n    if (lazy[k]\
    \ == oe) return;\n    if (k < n) {\n      lazy[k * 2 + 0] = h(lazy[k * 2 + 0],\
    \ lazy[k]);\n      lazy[k * 2 + 1] = h(lazy[k * 2 + 1], lazy[k]);\n    }\n   \
    \ node[k] = g(node[k], p(lazy[k], len));\n    lazy[k] = oe;\n  }\n\n  void update(int\
    \ a, int b, const U x) { update(a, b + 1, x, 1, 0, n); }\n\n  void update(int\
    \ a, int b, U x, int k, int l, int r) {\n    eval(k, r - l);\n    if (a <= l &&\
    \ b >= r) {\n      lazy[k] = h(lazy[k], x);\n      eval(k, r - l);\n    } else\
    \ if (a < r && b > l) {\n      update(a, b, x, k * 2 + 0, l, (l + r) >> 1);\n\
    \      update(a, b, x, k * 2 + 1, (l + r) >> 1, r);\n      node[k] = f(node[k\
    \ * 2 + 0], node[k * 2 + 1]);\n    }\n  }\n\n  T query(int a, int b) { return\
    \ query(a, b + 1, 1, 0, n); }\n\n  T query(int a, int b, int k, int l, int r)\
    \ {\n    eval(k, r - l);\n    if (a >= r || b <= l) return e;\n    if (a <= l\
    \ && b >= r) return node[k];\n    T vl = query(a, b, k * 2 + 0, l, (l + r) >>\
    \ 1);\n    T vr = query(a, b, k * 2 + 1, (l + r) >> 1, r);\n    return f(vl, vr);\n\
    \  }\n\n  T operator[](int idx) { return query(idx, idx + 1); }\n};\n\n\n"
  code: "#ifndef H_lazy_segment_tree\n#define H_lazy_segment_tree\n\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\ntemplate <typename T, typename U = T>\nclass LazySegmentTree\
    \ {\n public:\n  int n;\n  T e;\n  U oe;\n  vector<T> node;\n  vector<U> lazy;\n\
    \n  using F = function<T(T, T)>;\n  using G = function<T(T, U)>;\n  using H =\
    \ function<U(U, U)>;\n  using P = function<U(U, int)>;\n\n  const F f;\n  const\
    \ G g;\n  const H h;\n  const P p;\n\n  LazySegmentTree() {}\n  LazySegmentTree(int\
    \ n_, const T e_, const U oe_, const F f_, const G g_,\n                  const\
    \ H h_, const P p_)\n      : e(e_), oe(oe_), f(f_), g(g_), h(h_), p(p_) {\n  \
    \  n = 1;\n    while (n < n_) n <<= 1;\n    node.assign(2 * n, e);\n    lazy.assign(2\
    \ * n, oe);\n  }\n\n  void build() {\n    for (int i = n - 1; i > 0; --i) {\n\
    \      node[i] = f(node[i * 2 + 0], node[i * 2 + 1]);\n    }\n  }\n\n  void set(int\
    \ idx, T v) { node[idx + n] = v; }\n\n  void eval(int k, int len) {\n    if (lazy[k]\
    \ == oe) return;\n    if (k < n) {\n      lazy[k * 2 + 0] = h(lazy[k * 2 + 0],\
    \ lazy[k]);\n      lazy[k * 2 + 1] = h(lazy[k * 2 + 1], lazy[k]);\n    }\n   \
    \ node[k] = g(node[k], p(lazy[k], len));\n    lazy[k] = oe;\n  }\n\n  void update(int\
    \ a, int b, const U x) { update(a, b + 1, x, 1, 0, n); }\n\n  void update(int\
    \ a, int b, U x, int k, int l, int r) {\n    eval(k, r - l);\n    if (a <= l &&\
    \ b >= r) {\n      lazy[k] = h(lazy[k], x);\n      eval(k, r - l);\n    } else\
    \ if (a < r && b > l) {\n      update(a, b, x, k * 2 + 0, l, (l + r) >> 1);\n\
    \      update(a, b, x, k * 2 + 1, (l + r) >> 1, r);\n      node[k] = f(node[k\
    \ * 2 + 0], node[k * 2 + 1]);\n    }\n  }\n\n  T query(int a, int b) { return\
    \ query(a, b + 1, 1, 0, n); }\n\n  T query(int a, int b, int k, int l, int r)\
    \ {\n    eval(k, r - l);\n    if (a >= r || b <= l) return e;\n    if (a <= l\
    \ && b >= r) return node[k];\n    T vl = query(a, b, k * 2 + 0, l, (l + r) >>\
    \ 1);\n    T vr = query(a, b, k * 2 + 1, (l + r) >> 1, r);\n    return f(vl, vr);\n\
    \  }\n\n  T operator[](int idx) { return query(idx, idx + 1); }\n};\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/lazy_segment_tree.cpp
  requiredBy: []
  timestamp: '2021-09-04 15:28:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_I.test.cpp
  - test/aoj/DSL_2_F.test.cpp
  - test/aoj/DSL_2_H.test.cpp
documentation_of: DataStructure/lazy_segment_tree.cpp
layout: document
redirect_from:
- /library/DataStructure/lazy_segment_tree.cpp
- /library/DataStructure/lazy_segment_tree.cpp.html
title: DataStructure/lazy_segment_tree.cpp
---

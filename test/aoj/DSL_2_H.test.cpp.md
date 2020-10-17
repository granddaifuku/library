---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/lazy_segment_tree.cpp
    title: DataStructure/lazy_segment_tree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H&lang=ja
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H&lang=ja
  bundledCode: "#line 1 \"test/aoj/DSL_2_H.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H&lang=ja\"\
    \n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\n#line 1 \"DataStructure/lazy_segment_tree.cpp\"\
    \n\n\n\n#line 5 \"DataStructure/lazy_segment_tree.cpp\"\n\nusing namespace std;\n\
    \ntemplate <typename T, typename U = T>\nclass LazySegmentTree {\npublic:\n  int\
    \ n;\n  T e;\n  U oe;\n  vector<T> node;\n  vector<U> lazy;\n\n  using F = function<T(T,\
    \ T)>;\n  using G = function<T(T, U)>;\n  using H = function<U(U, U)>;\n  using\
    \ P = function<U(U, int)>;\n\n  const F f;\n  const G g;\n  const H h;\n  const\
    \ P p;\n  \n  LazySegmentTree() {}\n  LazySegmentTree(int n_, const T e_, const\
    \ U oe_, const F f_, const G g_, const H h_, const P p_) :\n\te(e_), oe(oe_),\
    \ f(f_), g(g_), h(h_), p(p_) {\n\tn = 1;\n\twhile (n < n_) n <<= 1;\n\tnode.assign(2\
    \ * n, e);\n\tlazy.assign(2 * n, oe);\n  }\n  \n  void build() {\n\tfor (int i\
    \ = n - 1; i > 0; --i) {\n\t  node[i] = f(node[i * 2 + 0], node[i * 2 + 1]);\n\
    \t}\n  }\n\n  void set(int idx, T v) {\n\tnode[idx + n] = v;\n  }\n\n  void eval(int\
    \ k, int len) {\n\tif (lazy[k] == oe) return;\n\tif (k < n) {\n\t  lazy[k * 2\
    \ + 0] = h(lazy[k * 2 + 0], lazy[k]);\n\t  lazy[k * 2 + 1] = h(lazy[k * 2 + 1],\
    \ lazy[k]);\n\t}\n\tnode[k] = g(node[k], p(lazy[k], len));\n\tlazy[k] = oe;\n\
    \  }\n\n  void update(int a, int b, const U x) {\n\tupdate(a, b + 1, x, 1, 0,\
    \ n);\n  }\n\n  void update(int a, int b, U x, int k, int l, int r) {\n\teval(k,\
    \ r - l);\n\tif (a <= l && b >= r) {\n\t  lazy[k] = h(lazy[k], x);\n\t  eval(k,\
    \ r - l);\n\t} else if (a < r && b > l) {\n\t  update(a, b, x, k * 2 + 0, l, (l\
    \ + r) >> 1);\n\t  update(a, b, x, k * 2 + 1, (l + r) >> 1, r);\n\t  node[k] =\
    \ f(node[k * 2 + 0], node[k * 2 + 1]);\n\t}\n  }\n\n  T query(int a, int b) {\n\
    \treturn query(a, b + 1, 1, 0, n);\n  }\n\n  T query(int a, int b, int k, int\
    \ l, int r) {\n\teval(k, r - l);\n\tif (a >= r || b <= l) return e;\n\tif (a <=\
    \ l && b >= r) return node[k];\n\tT vl = query(a, b, k * 2 + 0, l, (l + r) >>\
    \ 1);\n\tT vr = query(a, b, k * 2 + 1, (l + r) >> 1, r);\n\treturn f(vl, vr);\n\
    \  }\n\n  T operator[](int idx) {\n\treturn query(idx, idx + 1);\n  }\n};\n\n\n\
    #line 8 \"test/aoj/DSL_2_H.test.cpp\"\n\nusing ll = long long;\n\nconst int INF\
    \ = 1e9;\n\nint main() {\n  int n, q;\n  cin >> n >> q;\n  LazySegmentTree<int>\
    \ seg = LazySegmentTree<int>(n, INF, 0, [](int a, int b) { return min(a, b); },\n\
    \t\t\t\t\t\t\t\t\t\t\t\t  [](int a, int b) { return a + b; }, [](int a, int b)\
    \ { return a + b; }, [](int a, int b) { return a; });\n  for (int i = 0; i < n;\
    \ ++i) seg.set(i, 0);\n  seg.build();\n  for (int i = 0; i < q; ++i) {\n\tint\
    \ c, s, t;\n\tcin >> c >> s >> t;\n\tif (c) {\n\t  cout << seg.query(s, t) <<\
    \ endl;\n\t} else {\n\t  int x;\n\t  cin >> x;\n\t  seg.update(s, t, x);\n\t}\n\
    \  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H&lang=ja\"\
    \n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\n#include \"../../DataStructure/lazy_segment_tree.cpp\"\
    \n\nusing ll = long long;\n\nconst int INF = 1e9;\n\nint main() {\n  int n, q;\n\
    \  cin >> n >> q;\n  LazySegmentTree<int> seg = LazySegmentTree<int>(n, INF, 0,\
    \ [](int a, int b) { return min(a, b); },\n\t\t\t\t\t\t\t\t\t\t\t\t  [](int a,\
    \ int b) { return a + b; }, [](int a, int b) { return a + b; }, [](int a, int\
    \ b) { return a; });\n  for (int i = 0; i < n; ++i) seg.set(i, 0);\n  seg.build();\n\
    \  for (int i = 0; i < q; ++i) {\n\tint c, s, t;\n\tcin >> c >> s >> t;\n\tif\
    \ (c) {\n\t  cout << seg.query(s, t) << endl;\n\t} else {\n\t  int x;\n\t  cin\
    \ >> x;\n\t  seg.update(s, t, x);\n\t}\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - DataStructure/lazy_segment_tree.cpp
  isVerificationFile: true
  path: test/aoj/DSL_2_H.test.cpp
  requiredBy: []
  timestamp: '2020-10-17 17:50:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_H.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_H.test.cpp
- /verify/test/aoj/DSL_2_H.test.cpp.html
title: test/aoj/DSL_2_H.test.cpp
---

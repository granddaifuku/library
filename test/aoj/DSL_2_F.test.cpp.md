---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: DataStructure/lazy_segment_tree.cpp
    title: DataStructure/lazy_segment_tree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F
  bundledCode: "#line 1 \"test/aoj/DSL_2_F.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F\"\
    \n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\n#line 1 \"DataStructure/lazy_segment_tree.cpp\"\
    \n\n\n\n#line 5 \"DataStructure/lazy_segment_tree.cpp\"\n\nusing namespace std;\n\
    \ntemplate <typename T, typename U = T>\nclass LazySegmentTree {\npublic:\n  int\
    \ n, height;\n  T e;\n  U oe;\n  vector<T> node;\n  vector<U> lazy;\n  function<T(T,\
    \ T)> operation;\n  function<T(T, U)> apply;\n  function<U(U, U)> manage;\n\n\
    \  LazySegmentTree() {}\n  LazySegmentTree(int n_, T e_, U oe_, function<T(T,\
    \ T)> operation_, function<T(T, U)> apply_, function<U(U, U)> manage_) :\n\te(e_),\
    \ oe(oe_), operation(operation_), apply(apply_), manage(manage_) {\n\tn = 1, height\
    \ = 0;\n\twhile (n < n_) n <<= 1, height++;\n\tnode.assign(2 * n, e);\n\tlazy.assign(2\
    \ * n, oe);\n  }\n  \n  void build() {\n\tfor (int i = n - 1; i > 0; --i) {\n\t\
    \  node[i] = operation(node[i * 2 + 0], node[i * 2 + 1]);\n\t}\n  }\n\n  void\
    \ set(int idx, T v) {\n\tnode[idx + n] = v;\n  }\n\n  void eval(int k) {\n\tif\
    \ (lazy[k] == oe) return;\n\tif (k < n) {\n\t  lazy[k * 2 + 0] = manage(lazy[k\
    \ * 2 + 0], lazy[k]);\n\t  lazy[k * 2 + 1] = manage(lazy[k * 2 + 1], lazy[k]);\n\
    \t}\n\tnode[k] = apply(node[k], lazy[k]);\n\tlazy[k] = oe;\n  }\n\n  void update(int\
    \ a, int b, U x) {\n\tupdate(a, b, x, 0, 0, n);\n  }\n\n  void update(int a, int\
    \ b, U x, int k, int l, int r) {\n\teval(k);\n\tif (a <= l && r <= b) {\n\t  lazy[k]\
    \ = manage(lazy[k], x);\n\t  eval(k);\n\t} else if (a < r && l < b) {\n\t  update(a,\
    \ b, x, k * 2 + 0, l, (l + r) / 2);\n\t  update(a, b, x, k * 2 + 1, (l + r) /\
    \ 2, r);\n\t  node[k] = operation(node[2 * k + 0], node[2 * k + 1]);\n\t}\n  }\n\
    \n  T query(int a, int b) {\n\treturn query(a, b, 0, 0, n);\n  }\n\n  T query(int\
    \ a, int b, int k, int l, int r) {\n\teval(k);\n\tif (a >= r || b <= l) return\
    \ e;\n\tif (a <= l && b >= r) return node[k];\n\tT vl = query(a, b, 2 * k + 0,\
    \ l, (l + r) / 2);\n\tT vr = query(a, b, 2 * k + 1, (l + r) / 2, r);\n\treturn\
    \ operation(vl, vr);\n  }\n\n  // void update(int a, int b, U x) {\n  // \tevaluate(a\
    \ += n);\n  // \tevaluate(b += n - 1);\n  // \tfor (int l = a, r = b + 1; l <\
    \ r; l >>= 1, r >>= 1) {\n  // \t  if (l & 1) lazy[l] = manage(lazy[l], x), ++l;\n\
    \  // \t  if (r & 1) --r, lazy[r] = manage(lazy[r], x);\n  // \t}\n  // \tcalc(a);\n\
    \  // \tcalc(b);\n  // }\n\n  // T query(int a, int b) {\n  // \tevaluate(a +=\
    \ n);\n  // \tevaluate(b += n - 1);\n  // \tT L = e, R = e;\n  // \tfor (int l\
    \ = a, r = b + 1; l < r; l >>= 1, r >>= 1) {\n  // \t  if (l & 1) L = operation(L,\
    \ reflect(l++));\n  // \t  if (r & 1) R = operation(reflect(--r), R);\n  // \t\
    }\n\n  // \treturn operation(L, R);\n  // }\n\n  // inline void calc(int k) {\n\
    \  // \twhile (k >>= 1) node[k] = operation(reflect(2 * k + 0), reflect(2 * k\
    \ + 1));\n  // }\n\n  // inline void evaluate(int k) {\n  // \tfor (int i = height;\
    \ i > 0; --i) propagate(k >> i);\n  // }\n\n  // inline void propagate(int k)\
    \ {\n  // \tif (lazy[k] == oe) return;\n  // \tlazy[2 * k + 0] = manage(lazy[2\
    \ * k + 0], lazy[k]);\n  // \tlazy[2 * k + 1] = manage(lazy[2 * k + 1], lazy[k]);\n\
    \  // \tnode[k] = reflect(k);\n  // \tlazy[k] = oe;\n  // }\n\n  // inline T reflect(int\
    \ k) {\n  // \treturn lazy[k] == oe ? node[k] : apply(node[k], lazy[k]);\n  //\
    \ }\n\n  T operator[](int idx) {\n\treturn query(idx, idx + 1);\n  }\n};\n\n\n\
    #line 8 \"test/aoj/DSL_2_F.test.cpp\"\n\nusing ll = long long;\n\nconst ll INF\
    \ = 2147483647;\n\nint main() {\n  int n, q;\n  cin >> n >> q;\n  LazySegmentTree<ll>\
    \ seg = LazySegmentTree<ll>(n, INF, 0LL, [](ll a, ll b) { return min(a, b); },\
    \ \n\t\t\t\t\t\t\t\t\t\t\t\t  [](ll a, ll b) { return b; }, [](ll a, ll b) { return\
    \ b; });\n  for (int i = 0; i < q; ++i) {\n\tint type, s, t;\n\tcin >> type >>\
    \ s >> t;\n\tif (type) {\n\t  cout << seg.query(s, t + 1) << endl;\n\t} else {\n\
    \t  ll x;\n\t  cin >> x;\n\t  seg.update(s, t + 1, x);\n\t}\n  }\n  \n\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F\"\
    \n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\n#include \"../../DataStructure/lazy_segment_tree.cpp\"\
    \n\nusing ll = long long;\n\nconst ll INF = 2147483647;\n\nint main() {\n  int\
    \ n, q;\n  cin >> n >> q;\n  LazySegmentTree<ll> seg = LazySegmentTree<ll>(n,\
    \ INF, 0LL, [](ll a, ll b) { return min(a, b); }, \n\t\t\t\t\t\t\t\t\t\t\t\t \
    \ [](ll a, ll b) { return b; }, [](ll a, ll b) { return b; });\n  for (int i =\
    \ 0; i < q; ++i) {\n\tint type, s, t;\n\tcin >> type >> s >> t;\n\tif (type) {\n\
    \t  cout << seg.query(s, t + 1) << endl;\n\t} else {\n\t  ll x;\n\t  cin >> x;\n\
    \t  seg.update(s, t + 1, x);\n\t}\n  }\n  \n\n  return 0;\n}\n"
  dependsOn:
  - DataStructure/lazy_segment_tree.cpp
  isVerificationFile: true
  path: test/aoj/DSL_2_F.test.cpp
  requiredBy: []
  timestamp: '2020-10-07 23:17:11+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/DSL_2_F.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_F.test.cpp
- /verify/test/aoj/DSL_2_F.test.cpp.html
title: test/aoj/DSL_2_F.test.cpp
---

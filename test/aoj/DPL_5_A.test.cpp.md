---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/modint.cpp
    title: Math/modint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_A
  bundledCode: "#line 1 \"test/aoj/DPL_5_A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_A\"\
    \n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\n#line 1 \"Math/modint.cpp\"\
    \n\n\n\n#line 5 \"Math/modint.cpp\"\n\nusing namespace std;\n\ntemplate<typename\
    \ T, T Modulus = 1000000007>\nclass Modint {\npublic:\n  T v;\n  constexpr Modint(signed\
    \ v_) : v(v_) {}\n  constexpr Modint(long long v_ = 0) noexcept : v(v_ % Modulus)\
    \ {\n\tif (v < 0) v += Modulus;\n  }\n  constexpr int getMod() { return Modulus;\
    \ }\n  constexpr Modint operator - () const noexcept {\n\treturn v ? Modulus -\
    \ v : 0;\n  }\n  constexpr Modint operator + (const Modint& m) const noexcept\
    \ { return Modint(*this) += m; }\n  constexpr Modint operator - (const Modint&\
    \ m) const noexcept { return Modint(*this) -= m; }\n  constexpr Modint operator\
    \ * (const Modint& m) const noexcept { return Modint(*this) *= m; }\n  constexpr\
    \ Modint operator / (const Modint& m) const noexcept { return Modint(*this) /=\
    \ m; }\n  constexpr Modint& operator += (const Modint& m) noexcept {\n\tv += m.v;\n\
    \tif (v >= Modulus) v -= Modulus;\n\treturn *this;\n  }\n  constexpr Modint& operator\
    \ -= (const Modint& m) noexcept {\n\tv -= m.v;\n\tif (v < 0) v += Modulus;\n\t\
    return *this;\n  }\n  constexpr Modint& operator *= (const Modint& m) noexcept\
    \ {\n\tv = v * m.v % Modulus;\n\treturn *this;\n  }\n  constexpr Modint& operator\
    \ /= (const Modint& m) noexcept {\n\tlong long a = m.v, b = Modulus, t = 1, u\
    \ = 0;\n\twhile (b) {\n\t  long long w = a / b;\n\t  a -= w * b; swap(a, b);\n\
    \t  t -= w * u; swap(t, u);\n\t}\n\tv = v * u % Modulus;\n\tif (v < 0) v += Modulus;\n\
    \treturn *this;\n  }\n  constexpr bool operator == (const Modint& m) const noexcept\
    \ {\n\treturn this->v == m.v;\n  }\n  constexpr bool operator != (const Modint&\
    \ m) const noexcept {\n\treturn this->v != m.v;\n  }\n  constexpr bool operator\
    \ < (const Modint& m) const noexcept {\n\treturn this->v < m.v; \n  }\n  constexpr\
    \ bool operator > (const Modint& m) const noexcept {\n\treturn this->v > m.v;\
    \ \n  }\n  friend constexpr ostream& operator << (ostream &os, const Modint<T,\
    \ Modulus>& x) noexcept {\n\treturn os << x.v;\n  }\n  Modint pow (long long k)\
    \ {\n\tModint res(1), tmp(v);\n\twhile (k) {\n\t  if (k & 1) res *= tmp;\n\t \
    \ tmp *= tmp;\n\t  k >>= 1;\n\t}\t\n\treturn res;\n  }\n};\n\n\n#line 8 \"test/aoj/DPL_5_A.test.cpp\"\
    \n\nint main() {  \n  int n;\n  Modint<long long> mint;\n  cin >> n >> mint.v;\n\
    \  cout << mint.pow(n).v << endl;\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_A\"\
    \n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\n#include \"../../Math/modint.cpp\"\
    \n\nint main() {  \n  int n;\n  Modint<long long> mint;\n  cin >> n >> mint.v;\n\
    \  cout << mint.pow(n).v << endl;\n\n  return 0;\n}\n"
  dependsOn:
  - Math/modint.cpp
  isVerificationFile: true
  path: test/aoj/DPL_5_A.test.cpp
  requiredBy: []
  timestamp: '2020-10-16 01:08:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DPL_5_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DPL_5_A.test.cpp
- /verify/test/aoj/DPL_5_A.test.cpp.html
title: test/aoj/DPL_5_A.test.cpp
---

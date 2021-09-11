---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_A.test.cpp
    title: test/aoj/DPL_5_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_B.test.cpp
    title: test/aoj/DPL_5_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_D.test.cpp
    title: test/aoj/DPL_5_D.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/modint.cpp\"\n\n\n\n#include <bits/stdc++.h>\n\nusing\
    \ namespace std;\n\ntemplate<typename T = long long, T Modulus = 1000000007>\n\
    class Modint {\npublic:\n  T v;\n  constexpr Modint(signed v_) : v(v_) {}\n  constexpr\
    \ Modint(long long v_ = 0) noexcept : v(v_ % Modulus) {\n\tif (v < 0) v += Modulus;\n\
    \  }\n  Modint pow (long long k) {\n\tModint res(1), tmp(v);\n\twhile (k) {\n\t\
    \  if (k & 1) res *= tmp;\n\t  tmp *= tmp;\n\t  k >>= 1;\n\t}\t\n\treturn res;\n\
    \  }\n  \n  constexpr int getMod() { return Modulus; }\n  constexpr Modint operator\
    \ - () const noexcept {\n\treturn v ? Modulus - v : 0;\n  }\n  constexpr Modint\
    \ operator + (const Modint& m) const noexcept { return Modint(*this) += m; }\n\
    \  constexpr Modint operator - (const Modint& m) const noexcept { return Modint(*this)\
    \ -= m; }\n  constexpr Modint operator * (const Modint& m) const noexcept { return\
    \ Modint(*this) *= m; }\n  constexpr Modint operator / (const Modint& m) const\
    \ noexcept { return Modint(*this) /= m; }\n  constexpr Modint& operator += (const\
    \ Modint& m) noexcept {\n\tv += m.v;\n\tif (v >= Modulus) v -= Modulus;\n\treturn\
    \ *this;\n  }\n  constexpr Modint& operator -= (const Modint& m) noexcept {\n\t\
    v -= m.v;\n\tif (v < 0) v += Modulus;\n\treturn *this;\n  }\n  constexpr Modint&\
    \ operator *= (const Modint& m) noexcept {\n\tv = v * m.v % Modulus;\n\treturn\
    \ *this;\n  }\n  constexpr Modint& operator /= (const Modint& m) noexcept {\n\t\
    long long a = m.v, b = Modulus, t = 1, u = 0;\n\twhile (b) {\n\t  long long w\
    \ = a / b;\n\t  a -= w * b; swap(a, b);\n\t  t -= w * u; swap(t, u);\n\t}\n\t\
    v = v * t % Modulus;\n\tif (v < 0) v += Modulus;\n\treturn *this;\n  }\n  constexpr\
    \ bool operator == (const Modint& m) const noexcept {\n\treturn this->v == m.v;\n\
    \  }\n  constexpr bool operator != (const Modint& m) const noexcept {\n\treturn\
    \ this->v != m.v;\n  }\n  constexpr bool operator < (const Modint& m) const noexcept\
    \ {\n\treturn this->v < m.v; \n  }\n  constexpr bool operator > (const Modint&\
    \ m) const noexcept {\n\treturn this->v > m.v; \n  }\n  friend constexpr ostream&\
    \ operator << (ostream &os, const Modint<T, Modulus>& x) noexcept {\n\treturn\
    \ os << x.v;\n  }\n};\n\n\n"
  code: "#ifndef H_modint\n#define H_modint\n\n#include <bits/stdc++.h>\n\nusing namespace\
    \ std;\n\ntemplate<typename T = long long, T Modulus = 1000000007>\nclass Modint\
    \ {\npublic:\n  T v;\n  constexpr Modint(signed v_) : v(v_) {}\n  constexpr Modint(long\
    \ long v_ = 0) noexcept : v(v_ % Modulus) {\n\tif (v < 0) v += Modulus;\n  }\n\
    \  Modint pow (long long k) {\n\tModint res(1), tmp(v);\n\twhile (k) {\n\t  if\
    \ (k & 1) res *= tmp;\n\t  tmp *= tmp;\n\t  k >>= 1;\n\t}\t\n\treturn res;\n \
    \ }\n  \n  constexpr int getMod() { return Modulus; }\n  constexpr Modint operator\
    \ - () const noexcept {\n\treturn v ? Modulus - v : 0;\n  }\n  constexpr Modint\
    \ operator + (const Modint& m) const noexcept { return Modint(*this) += m; }\n\
    \  constexpr Modint operator - (const Modint& m) const noexcept { return Modint(*this)\
    \ -= m; }\n  constexpr Modint operator * (const Modint& m) const noexcept { return\
    \ Modint(*this) *= m; }\n  constexpr Modint operator / (const Modint& m) const\
    \ noexcept { return Modint(*this) /= m; }\n  constexpr Modint& operator += (const\
    \ Modint& m) noexcept {\n\tv += m.v;\n\tif (v >= Modulus) v -= Modulus;\n\treturn\
    \ *this;\n  }\n  constexpr Modint& operator -= (const Modint& m) noexcept {\n\t\
    v -= m.v;\n\tif (v < 0) v += Modulus;\n\treturn *this;\n  }\n  constexpr Modint&\
    \ operator *= (const Modint& m) noexcept {\n\tv = v * m.v % Modulus;\n\treturn\
    \ *this;\n  }\n  constexpr Modint& operator /= (const Modint& m) noexcept {\n\t\
    long long a = m.v, b = Modulus, t = 1, u = 0;\n\twhile (b) {\n\t  long long w\
    \ = a / b;\n\t  a -= w * b; swap(a, b);\n\t  t -= w * u; swap(t, u);\n\t}\n\t\
    v = v * t % Modulus;\n\tif (v < 0) v += Modulus;\n\treturn *this;\n  }\n  constexpr\
    \ bool operator == (const Modint& m) const noexcept {\n\treturn this->v == m.v;\n\
    \  }\n  constexpr bool operator != (const Modint& m) const noexcept {\n\treturn\
    \ this->v != m.v;\n  }\n  constexpr bool operator < (const Modint& m) const noexcept\
    \ {\n\treturn this->v < m.v; \n  }\n  constexpr bool operator > (const Modint&\
    \ m) const noexcept {\n\treturn this->v > m.v; \n  }\n  friend constexpr ostream&\
    \ operator << (ostream &os, const Modint<T, Modulus>& x) noexcept {\n\treturn\
    \ os << x.v;\n  }\n};\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/modint.cpp
  requiredBy: []
  timestamp: '2020-10-17 00:04:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DPL_5_B.test.cpp
  - test/aoj/DPL_5_D.test.cpp
  - test/aoj/DPL_5_A.test.cpp
documentation_of: Math/modint.cpp
layout: document
redirect_from:
- /library/Math/modint.cpp
- /library/Math/modint.cpp.html
title: Math/modint.cpp
---

#ifndef H_modint
#define H_modint

#include <bits/stdc++.h>

using namespace std;

template<typename T, T Modulus = 1000000007>
class Modint {
public:
  T v;
  constexpr Modint(signed v_) : v(v_) {}
  constexpr Modint(long long v_ = 0) noexcept : v(v_ % Modulus) {
	if (v < 0) v += Modulus;
  }
  constexpr int getMod() { return Modulus; }
  constexpr Modint operator - () const noexcept {
	return v ? Modulus - v : 0;
  }
  constexpr Modint operator + (const Modint& m) const noexcept { return Modint(*this) += m; }
  constexpr Modint operator - (const Modint& m) const noexcept { return Modint(*this) -= m; }
  constexpr Modint operator * (const Modint& m) const noexcept { return Modint(*this) *= m; }
  constexpr Modint operator / (const Modint& m) const noexcept { return Modint(*this) /= m; }
  constexpr Modint& operator += (const Modint& m) noexcept {
	v += m.v;
	if (v >= Modulus) v -= Modulus;
	return *this;
  }
  constexpr Modint& operator -= (const Modint& m) noexcept {
	v -= m.v;
	if (v < 0) v += Modulus;
	return *this;
  }
  constexpr Modint& operator *= (const Modint& m) noexcept {
	v = v * m.v % Modulus;
	return *this;
  }
  constexpr Modint& operator /= (const Modint& m) noexcept {
	long long a = m.v, b = Modulus, t = 1, u = 0;
	while (b) {
	  long long w = a / b;
	  a -= w * b; swap(a, b);
	  t -= w * u; swap(t, u);
	}
	v = v * u % Modulus;
	if (v < 0) v += Modulus;
	return *this;
  }
  constexpr bool operator == (const Modint& m) const noexcept {
	return this->v == m.v;
  }
  constexpr bool operator != (const Modint& m) const noexcept {
	return this->v != m.v;
  }
  constexpr bool operator < (const Modint& m) const noexcept {
	return this->v < m.v; 
  }
  constexpr bool operator > (const Modint& m) const noexcept {
	return this->v > m.v; 
  }
  friend constexpr ostream& operator << (ostream &os, const Modint<T, Modulus>& x) noexcept {
	return os << x.v;
  }
  Modint pow (long long k) {
	Modint res(1), tmp(v);
	while (k) {
	  if (k & 1) res *= tmp;
	  tmp *= tmp;
	  k >>= 1;
	}
	
	return res;
  }
};

#endif

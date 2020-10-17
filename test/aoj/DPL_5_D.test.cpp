#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_D"

#include <bits/stdc++.h>

using namespace std;

#include "../../Math/modint.cpp"

int main() {
  int n, k;
  cin >> n >> k;
  Modint<> res = Modint<>(1);
  for (int i = 1; i < n + k; ++i) res *= i;
  for (int i = 1; i < n + 1; ++i) res /= i;
  for (int i = 1; i < k; ++i) res /= i;
  cout << res << endl;

  return 0;
}

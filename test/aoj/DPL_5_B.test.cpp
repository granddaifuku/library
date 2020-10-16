#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_B"

#include <bits/stdc++.h>

using namespace std;

#include "../../Math/modint.cpp"

int main() {
  int n, k;
  Modint<> mint = Modint<>(1);
  cin >> n >> k;
  if (n > k) {
	cout << 0 << endl;
	return 0;
  }
  for (int i = k, j = 0; j < n; --i, ++j) mint *= i;
  cout << mint.v << endl;
  
}

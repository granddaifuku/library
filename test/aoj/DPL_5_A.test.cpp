#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_A"

#include <bits/stdc++.h>

using namespace std;

#include "../../Math/modint.cpp"

int main() {  
  int n;
  Modint<long long> mint;
  cin >> n >> mint.v;
  cout << mint.pow(n).v << endl;

  return 0;
}

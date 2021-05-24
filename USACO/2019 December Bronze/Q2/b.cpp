// ––– USACO 2019 December Bronze: Problem B –––

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back
using str = string;
using ll = long long;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;

int n;
str farms;

bool check(int k) {
  set<str> seqs;
  for (int i = 0; i <= n - k; i++) {
    str seq = farms.substr(i, k);
    if (seqs.count(seq)) {
      return false;
    }
    seqs.insert(seq);
  }
  return true;
}

int main()
{
  ifstream cin("whereami.in");
  ofstream cout("whereami.out");

  cin >> n >> farms;

  for (int i = 1; i <= n; i++) {
    if (check(i)) {
      cout << i; break;
    }
  }
}

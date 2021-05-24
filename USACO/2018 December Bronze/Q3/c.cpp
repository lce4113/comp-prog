// ––– USACO 2018 December Bronze: Problem C –––

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

set<int> results;

void recurse(int n, vi arr1, vi arr2, int tank, int rm) {
  if (n == 4) {
    results.insert(tank);
    return;
  }

  if (n == 0) {
    for (int i = 0; i < arr1.size(); i++) {
      recurse(1, arr1, arr2, tank - arr1[i], i);
    }
  } else if (n % 2 == 1) {
    arr2.pb(arr1[rm]);
    arr1.erase(arr1.begin() + rm);
    for (int i = 0; i < arr2.size(); i++) {
      recurse(n+1, arr1, arr2, tank + arr2[i], i);
    }
  } else {
    arr1.pb(arr2[rm]);
    arr2.erase(arr2.begin() + rm);
    for (int i = 0; i < arr1.size(); i++) {
      recurse(n+1, arr1, arr2, tank + arr1[i], i);
    }
  }
}

int main()
{
  /* ifstream cin("backforth.in"); */
  /* ofstream cout("backforth.out"); */

  vi arr1;
  vi arr2;
  for (int i = 0; i < 10; i++) {
    int x;
    cin >> x;
    arr1.pb(x);
  }
  for (int i = 0; i < 10; i++) {
    int x;
    cin >> x;
    arr2.pb(x);
  }

  int sm = 0;
  for (int elt : arr1) sm += elt;
  recurse(0, arr1, arr2, sm, 0);

  cout << results.size();
}

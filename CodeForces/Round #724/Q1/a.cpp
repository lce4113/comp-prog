// ––– CodeForces Round #724: Problem A –––

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

bool has(vi arr, int m)
{
  for (int x : arr) {
    if (x == m) {
      return true;
    }
  }
  return false;
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    set<int> arr;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      arr.insert(x);
    }

    set<int> b;
    for (int x : arr) {
      for (int y : arr) {
        int a = abs(x - y);
        if (a != 0)
          b.insert(a);
      }
    }
    for (int x : b) {
      arr.insert(x);
    }

    bool B = true;
    while (B) {
      if (arr.size() > 300) {
        cout << "NO";
        goto done;
      }
      B = false;
      set<int> c;
      for (int x : b) {
        for (int y : arr) {
          int a = abs(y - x);
          if (arr.count(a) == 0 && a != 0) {
            B = true;
            arr.insert(a);
            c.insert(a);
          }
        }
      }
      b.clear();
      for (int x : c) {
        b.insert(x);
      }
    }

    cout << "YES" << '\n';
    cout << arr.size() << '\n';
    for (int x : arr) {
      cout << x << ' ';
    }
  done:
    cout << '\n';
  }
}

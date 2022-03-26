// ––– CodeForces Round #719: Problem A –––

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

bool check(int n, char arr[], char ch)
{
  for (int j = 0; j <= n; j++) {
    if (arr[j] == ch) {
      return true;
    }
  }
  return false;
}

int main()
{
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    str st;
    cin >> st;

    set<char> c;
    bool b = false;
    char last = '0';
    for (int i = 0; i < n; i++) {
      char ch = st[i];
      if (i > 0 && last != ch) {
        if (c.count(ch) == 1) {
          cout << "NO" << endl;
          b = true;
          break;
        }
      }
      c.insert(ch);
      last = ch;
    }
    if (!b)
      cout << "YES" << endl;
  }
}

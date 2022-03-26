// ––– Educational Round #107: Problem D –––

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

str alphabet = "abcdefghijklmnopqrstuvwxyz";

int main()
{
  ll n;
  int k;
  cin >> n >> k;

  str ans;
  for (int i = 0; i < k; i++) {
    ans += alphabet[i];
    for (int l = i + 1; l < k; l++) {
      ans += alphabet[i];
      ans += alphabet[l];
    }
  }
  ans += alphabet[0];

  str ans2 = ans;
  while (ans2.length() < n)
    ans2 += ans;
  cout << ans2.substr(0, n);
}

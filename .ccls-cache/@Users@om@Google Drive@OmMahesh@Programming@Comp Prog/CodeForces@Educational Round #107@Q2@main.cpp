// ––– Educational Round #107: Problem B –––

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

int main()
{
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;

    int n1 = pow(10, a - 1), n2 = pow(10, b - 1) + pow(10, c - 1);

    cout << n1 << ' ' << n2 << endl;
  }
}

// ––– CodeForces Round #721: Problem B1 –––

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
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    char arr[n];
    int num = 0;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      if (arr[i] == '0')
        num++;
    }

    if (n % 2 == 1 && arr[n / 2] == '0') {
      if (num == 1)
        cout << "BOB" << '\n';
      else
        cout << "ALICE" << '\n';
    } else {
      cout << "BOB" << '\n';
    }
  }
}

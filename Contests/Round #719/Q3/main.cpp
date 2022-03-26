// ––– CodeForces Round #719: Problem C –––

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
    int num;
    cin >> num;

    if (num == 2) {
      cout << -1 << endl;
      continue;
    }

    int n = 1;
    for (int i = 0; i < num; i++) {
      for (int j = 0; j < num; j++) {
        if (n > num * num)
          n = 2;
        cout << n << ' ';
        n += 2;
      }
      cout << endl;
    }
  }
}

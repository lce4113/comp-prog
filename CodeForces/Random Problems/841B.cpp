// ––– CodeForces Contest 841, Problem B: "Godsend" –––

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

  int n;
  cin >> n;

  int arr[n], odd = 0, even = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x % 2) {
      odd++;
    } else {
      even++;
    }
  }

  if (odd >= 1) {
    cout << "First" << '\n';
  } else {
    cout << "Second" << '\n';
  }
}

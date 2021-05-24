// ––– CodeForces Nezzar and Colorful Balls: Problem A –––

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

    multiset<int> st;
    int m = -1;
    for (int i = 0; i < n; i++) {
      int elt;
      cin >> elt;
      st.insert(elt);
      int c = st.count(elt);
      if (c > m)
        m = c;
    }

    cout << m << '\n';
  }
}

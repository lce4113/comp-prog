// ––– CodeForces "AccurateLee": Problem B –––

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
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    vector<char> ans;
    bool b = false;
    for (int i = 0; i < n; i++) {
      if (b && arr[i] == '0') {
        ans.pb('0');
        break;
      } else if (arr[i] == '1')
        b = true;
      else
        ans.pb('0');
    }

    for (int i = n - 1; i >= 0; i--) {
      if (arr[i] == '0')
        break;
      else
        ans.pb('1');
    }

    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i];
    }
    if (ans.empty())
      cout << 0;
    cout << '\n';
  }
}

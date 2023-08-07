// USACO 2023 January Silver: Problem C

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long

int32_t main() {
  int n;
  cin >> n;
  int arr[n], even[n];
  int end = 0;
  vector<char> ans;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    arr[i] /= 2;
    even[i] = 0;
  }
  for (int i = n - 1; i >= 0; i--) {
    if (arr[i] % 2 == 0)
      even[i] = 1, arr[i]++;
    else
      break;
  }

  int i = 0;
  while (arr[n - 1] != 0) {
    while (i >= 0 && i < n && arr[i] == 1) {
      if (!even[i]) ans.pb('R');
      arr[i++]--;
    }
    while (i < n && arr[i] != 1) ans.pb('R'), arr[i++]--;
    /* for (int k = 0; k < n; k++) cout << arr[k] << ' '; */
    /* cout << '\n'; */
    i--;
    while (i >= 0 && arr[i] != 0) ans.pb('L'), arr[i--]--;
    /* for (int k = 0; k < n; k++) cout << arr[k] << ' '; */
    /* cout << '\n'; */
    i++;
  }

  for (int i = 0; i < ans.size(); i++) cout << ans[i];
  for (int i = ans.size() - 1; i >= 0; i--) {
    if (ans[i] == 'L')
      cout << 'R';
    else
      cout << 'L';
  }
  cout << '\n';
}

// ––– CodeForces Round #579: Problem E –––

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

  int arr[n];
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr[i] = x;
  }

  sort(arr, arr + n);

  set<int> ans;
  for (int i = 0; i < n; i++) {
    if (!ans.count(arr[i] - 1) && arr[i] != 1) {
      ans.insert(arr[i] - 1);
    } else if (!ans.count(arr[i])) {
      ans.insert(arr[i]);
    } else if (!ans.count(arr[i] + 1)) {
      ans.insert(arr[i] + 1);
    }
  }

  cout << ans.size() << '\n';
}

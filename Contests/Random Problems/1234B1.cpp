// ––– CodeForces Round #590: Problem B1 –––

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

bool has(vi vec, int num)
{
  for (int i = 0; i < vec.size(); i++) {
    if (num == vec[i])
      return true;
  }
  return false;
}

int main()
{
  int n, k;
  cin >> n >> k;

  vi ans;
  for (int i = 0; i < n; i++) {
    int elt;
    cin >> elt;
    if (!has(ans, elt)) {
      ans.insert(ans.begin(), elt);
      if (ans.size() > k)
        ans.erase(ans.end() - 1);
    }
  }

  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << ' ';
  }
}

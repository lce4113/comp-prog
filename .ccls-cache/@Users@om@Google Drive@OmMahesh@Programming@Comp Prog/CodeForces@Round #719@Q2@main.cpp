// ––– CodeForces Round #719: Problem B –––

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

vi digits(int num)
{
  vi d;
  while (num > 0) {
    d.insert(d.begin(), num % 10);
    num /= 10;
  }
  return d;
}

bool check(vi nums)
{
  for (int i = 1; i < nums.size(); i++) {
    if (nums[i] < nums[0])
      return false;
  }
  return true;
}

int count(vi nums)
{
  bool lmin = check(nums);

  if (lmin) {
    return nums[0] + (nums.size() - 1) * 9;
  }
  return nums[0] - 1 + (nums.size() - 1) * 9;
}

int ones(int n)
{
  if (n == 1)
    return 1;
  return ones(n - 1) * 10 + 1;
}

int main()
{
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;

    vi d = digits(num);
    int ans = (d.size() - 1) * 9;
    ans += num / ones(d.size());
    cout << ans << endl;
  }
}

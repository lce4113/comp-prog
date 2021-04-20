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
using vi = vector<int, int>;
using vl = vector<ll, ll>;

int includes(int arr[7], int a)
{
  for (int o = 0; o < 7; o++) {
    if (arr[o] == a)
      return 1;
  }
  return 0;
}

int test(int n, int nums[], int a, int b, int c)
{
  /* cout << a << ' ' << b << ' ' << c << endl; */
  int possibleNums[7] = { a, b, c, a + b, a + c, b + c, a + b + c };
  for (int m = 0; m < n; m++) {
    if (includes(possibleNums, nums[m]) == 0)
      return 0;
  }
  return 1;
}

int main()
{
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;

    int nums[n];
    for (int j = 0; j < n; j++) {
      int num;
      cin >> num;
      nums[j] = num;
    }

    sort(nums, nums + n);

    int total = 0;
    for (int j = 1; j <= nums[n - 1]; j++) {
      for (int k = 1; k <= j; k++) {
        for (int l = 1; l <= k; l++) {
          total += test(n, nums, j, k, l);
        }
      }
    }
    cout << total << endl;
  }
}

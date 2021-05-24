#include <bits/stdc++.h>

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

using namespace std;

int getScorePos(int n, int arr[], int low, int high)
{
  if (high - low <= 1) {
    return low + 1;
  }
  int mid = (low + high) / 2;
  if (arr[mid] < mid + 1) {
    return getScorePos(n, arr, low, mid);
  }
  return getScorePos(n, arr, mid, high);
}

int main()
{
  int n;
  cin >> n;

  int papers[n];
  for (int i = 0; i < n; i++) {
    cin >> papers[i];
  }

  sort(papers, papers + n, greater<int>());

  int pos = getScorePos(n, papers, 0, n);
}

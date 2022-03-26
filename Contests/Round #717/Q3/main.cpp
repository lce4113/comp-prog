// ––– Round #717: Problem C –––

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

int main() {
  int n;
  cin >> n;
  int arr[n], total;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    total += arr[i];
  }

  vi rm;

  cout << rm.size() << endl;
  for (int i = 0; i < rm.size(); i++) {
    cout << rm[i] << ' ';
  }
  cout << endl;
}

// ––– USACO 2017 December Bronze: Problem B –––

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
  ifstream cin("shuffle.in");
  ofstream cout("shuffle.out");

  int n;
  cin >> n;

  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int id1[n];
  for (int i = 0; i < n; i++) {
    cin >> id1[i];
  }

  int id2[n];
  for (int i = 0; i < n; i++) {
    /* id2[a[i] - 1] = id1[i]; */
    id2[i] = id1[a[i] - 1];
  }

  int id3[n];
  for (int i = 0; i < n; i++) {
    /* id3[a[i] - 1] = id2[i]; */
    id3[i] = id2[a[i] - 1];
  }

  int id4[n];
  for (int i = 0; i < n; i++) {
    /* id4[a[i] - 1] = id3[i]; */
    id4[i] = id3[a[i] - 1];
  }

  for (int i = 0; i < n; i++) {
    cout << id4[i] << '\n';
  }
}

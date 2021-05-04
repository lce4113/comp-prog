// ––– Educational Round #107: Problem C –––

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

int find1(int e, int arr2[], int num)
{
  for (int i = e - 1; i >= 0; i--) {
    if (arr2[i] == num) {
      return e - i - 1;
    }
  }
  return -1;
}

int find2(int e, vi arr, int num)
{
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] == num) {
      return i;
    }
  }
  return -1;
}

int find(int n, vi vec, int num)
{
  for (int i = 0; i < n; i++) {
    if (vec[i] == num) {
      return i + 1;
    }
  }
  return -1;
}

int main()
{
  int n, q;
  cin >> n >> q;

  vi cards;
  for (int i = 0; i < n; i++) {
    int c;
    cin >> c;
    cards.pb(c);
  }

  int queries[q];
  for (int i = 0; i < q; i++) {
    cin >> queries[i];
  }

  for (int i = 0; i < q; i++) {
    int query = queries[i];
    int pos = find(n, cards, query);
    cards.erase(cards.begin() + pos - 1);
    cards.insert(cards.begin(), query);
    cout << pos << ' ';
  }

  /* for (int i = 0; i < q; i++) { */
  /*   int query = queries[i]; */
  /*   int pos = find(i, queries, query); */
  /*   if (pos == -1) pos == find(i, cards, query); */
  /*   cards.erase(cards.begin() + pos - 1); */
  /*   cout << pos << ' '; */
  /* } */
}

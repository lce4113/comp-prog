// ––– CodeForces Homework: Problem A –––
// hEhE stealing from bCkTpTt is fun

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

#define MAXN 100100

int n, k;
char a[MAXN];
int freq[MAXN];
set<pair<int, char>> res;

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  cin >> a;
  n = strlen(a);
  cin >> k;

  for (int i = 'a'; i <= 'z'; i++)
    freq[i] = 0;

  for (int i = 0; i < n; i++)
    freq[a[i]]++;

  for (int i = 'a'; i <= 'z'; i++)
    res.insert(make_pair(freq[i], i));

  set<char> tr;
  int tosofar = 0;
  while (res.size()) {
    auto i = *res.begin();
    if (tosofar + i.f > k)
      break;
    tosofar += i.f;
    tr.insert(i.s);
    res.erase(res.begin());
  }

  cout << 26 - tr.size() << '\n';
  for (int i = 0; i < n; i++)
    if (tr.find(a[i]) == tr.end())
      cout << a[i];
  cout << '\n';
}

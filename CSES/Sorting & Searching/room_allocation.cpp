// CSES Sorting & Searching: Room Allocation

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

#define MAXN 200000

struct guest {
  int l, r, i;
};

bool cmp(guest a, guest b) {
  return a.l < b.l;
}

guest guests[MAXN];
int ans[MAXN];

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> guests[i].l >> guests[i].r;
    guests[i].i = i;
  }

  sort(guests, guests + n, cmp);

  priority_queue<pi, vector<pi>, greater<pi>> rooms;
  for (int i = 0; i < n; i++) {
    if (rooms.empty() || guests[i].l <= rooms.top().f) {
      ans[guests[i].i] = rooms.size() + 1;
    } else {
      ans[guests[i].i] = rooms.top().s;
      rooms.pop();
    }
    rooms.push(mp(guests[i].r, ans[guests[i].i]));
  }

  cout << rooms.size() << '\n';
  for (int i = 0; i < n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
}
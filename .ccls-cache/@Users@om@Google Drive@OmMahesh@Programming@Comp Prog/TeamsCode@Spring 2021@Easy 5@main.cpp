// ––– TeamsCode Spring 2021 Easy #5 –––

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
  str t;
  int a, b;
  cin >> t >> a >> b;
  int c = b * 60 / a;

  int t2 = stoi(t.substr(3, 5)) + c;
  int t1 = (stoi(t.substr(0, 2)) + t2 / 60) % 24;
  t2 = t2 % 60;

  str st1, st2;
  if (t1 < 10) {
    st1 = '0' + to_string(t1);
  } else {
    st1 = to_string(t1);
  }
  if (t2 < 10) {
    st2 = '0' + to_string(t2);
  } else {
    st2 = to_string(t2);
  }
  cout << st1 << ':' << st2 << endl;
}

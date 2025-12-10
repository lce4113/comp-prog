// ––– Round #715: Problem B –––

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
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;

    if (n % 3 != 0) {
      cout << "NO" << endl;
      continue;
    }

    int m = 0, t = 0;
    char c;
    char st[n];
    for (int k = 0; k < n; k++) {
      cin >> c;
      if (c == 'T')
        t++;
      else
        m++;
      st[k] = c;
    }
    if (2 * m != t) {
      cout << "NO" << endl;
      continue;
    }

    int left[m], right[m], T = 0, l = 0;
    for (int k = 0; k < n; k++) {
      if (st[k] == 'T')
        T++;
      else {
        left[l] = T;
        right[l++] = t - T;
      }
    }

    sort(left, left + m);
    sort(right, right + m);

    bool b = false;
    for (int k = 0; k < m; k++) {
      if (left[k] < k + 1) {
        cout << "NO" << endl;
        b = true;
        break;
      }
      if (right[k] < k + 1) {
        cout << "NO" << endl;
        b = true;
        break;
      }
    }
    if (b)
      continue;

    cout << "YES" << endl;

    /* bool T = false, TM = false, b = false; */
    /* for (int k = 0; k < n / 3 - 1; k++) { */
    /*   for (int l = 0; l < n; l++) { */
    /*     if (T) { */
    /*       if (s[l] == 'M') { */
    /*         TM = true; */
    /*         s.erase(s.begin() + l); */
    /*       } */
    /*     } else if (TM) { */
    /*       if (s[l] == 'T') { */
    /*         T = false; */
    /*         TM = false; */
    /*         s.erase(s.begin() + l); */
    /*       } */
    /*     } else if (s[l] == 'T') { */
    /*       T = true; */
    /*       s.erase(s.begin() + l); */
    /*     } else { */
    /*       cout << "NO" << endl; */
    /*       b = true; */
    /*       break; */
    /*     } */
    /*   } */
    /*   if (b) */
    /*     break; */
    /* } */
    /* if (b) */
    /*   continue; */
  }
}

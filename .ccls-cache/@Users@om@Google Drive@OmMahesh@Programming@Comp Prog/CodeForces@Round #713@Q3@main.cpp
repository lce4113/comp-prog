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

void reduce(char arr[], int j, int e, int& aLeft, int& bLeft)
{
  if (arr[j] == '0') {
    aLeft -= e;
  } else if (arr[j] == '1') {
    bLeft -= e;
  }
}

int main()
{
  int m;
  cin >> m;

  for (int i = 0; i < m; i++) {
    int a, aLeft, b, bLeft;
    cin >> a >> b;
    aLeft = a;
    bLeft = b;

    char arr[a + b];
    for (int j = 0; j < a + b; j++) {
      cin >> arr[j];
    }

    if (a % 2 == 1 && b % 2 == 1) {
      cout << -1 << endl;
      continue;
    }

    bool neg = false;
    for (int j = 0; j < (a + b) / 2; j++) {
      if (arr[a + b - 1 - j] == '?' && arr[j] != '?') {
        arr[a + b - 1 - j] = arr[j];
      } else if (arr[j] == '?') {
        arr[j] = arr[a + b - 1 - j];
      } else if (arr[j] != arr[a + b - 1 - j]) {
        neg = true;
        break;
      }
      if (arr[j] == '0') {
        aLeft -= 2;
      }
      if (arr[j] == '1') {
        bLeft -= 2;
      }
    }
    if (neg) {
      cout << -1 << endl;
      continue;
    }
    if ((a + b) % 2 == 1 && arr[(a + b) / 2] == '0') {
      aLeft--;
    } else if ((a + b) % 2 == 1 && arr[(a + b) / 2] == '1') {
      bLeft--;
    }

    if (aLeft % 2 == 1) {
      if (arr[(a + b) / 2] == '?') {
        arr[(a + b) / 2] = '0';
        aLeft--;
      }
    } else if (bLeft % 2 == 1) {
      if (arr[(a + b) / 2] == '?') {
        arr[(a + b) / 2] = '1';
        bLeft--;
      }
    }

    if (aLeft < 0 || bLeft < 0) {
      cout << -1 << endl;
      continue;
    }

    for (int j = 0; j < (a + b) / 2; j++) {
      if (arr[j] == '?') {
        if (aLeft > 0) {
          arr[j] = '0';
          arr[a + b - 1 - j] = '0';
          aLeft -= 2;
        } else {
          arr[j] = '1';
          arr[a + b - 1 - j] = '1';
        }
      }
    }

    for (int j = 0; j < a + b; j++) {
      cout << arr[j];
    }
    cout << endl;
  }
}

// Round #711: Problem A

#include <bits/stdc++.h>
using ll = long long;

using namespace std;

ll sumDigits(ll num)
{
  ll numCopy = num;
  ll sum = 0;
  sum += numCopy % 10;
  while (numCopy >= 10) {
    numCopy /= 10;
    sum += numCopy % 10;
  }
  return sum;
}

int main()
{
  int n;
  cin >> n;

  int out[n];
  for (int i = 0; i < n; i++) {
    ll num, digits;
    cin >> num;

    ll g = 1, j = -1;
    while (g == 1) {
      j++;
      g = gcd(num + j, sumDigits(num + j));
    }
    out[i] = num + j;
  }

  cout << out[0];
  for (int i = 1; i < n; i++) {
    cout << endl
         << out[i];
  }
}

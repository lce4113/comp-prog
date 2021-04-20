// ––– 2020 January: Bronze #2 –––

#include <fstream>
#include <iostream>

using namespace std;

int main() {
  ifstream fin("cow.in");

  int n;
  cin >> n;
  // fin >> n;

  int cows[n];
  for (int i = 0; i < n; ++i) {
    int num;

    cin >> num;
    // fin >> num;

    cows[i] = num;
  }

  int even = 0, odd = 0;
  for (int i = 0; i < n; ++i) {
    if (cows[i] % 2 == 0)
      even++;
    else
      odd++;
  }

  int m;
  if (even > odd) {
    m = 2 * odd + 1;
  } else if (even == odd) {
    m = 2 * odd - 1;
  } else if ((odd - even) % 3 == 0) {
    m = 2 * even + 2 * ((odd - even) / 3);
  } else if ((odd - even) % 3 == 1) {
    m = 2 * even + 2 * ((odd - even) / 3) - 1;
  } else {
    m = 2 * even + 2 * ((odd - even) / 3) + 1;
  }

  cout << m;
}

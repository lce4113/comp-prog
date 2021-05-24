#include <fstream>
#include <iostream>

using namespace std;

int main() {
  ifstream fin("swap.in");
  ofstream fout("swap.out");

  int n, k, a1, a2, b1, b2;
  fin >> n >> k >> a1 >> a2 >> b1 >> b2;
  a1--, a2--, b1--, b2--;

  int cows[n];
  for (int i = 0; i < n; i++) {
    cows[i] = i + 1;
  }

  int newCows[n];
  int minReverse = min(a1, b1);
  int maxReverse = max(a2, b2);
  for (int i = 0; i < minReverse; i++) {
    newCows[i] = cows[i];
  }
  for (int i = maxReverse + 1; i < n; i++) {
    newCows[i] = cows[i];
  }

  for (int i = minReverse; i <= maxReverse; i++) {
    if (i < a1 || i > a2) {
      if (k % 2 == 0) {
        newCows[i] = cows[i];
      } else {
        newCows[i] = cows[a2 - (i - a1)];
      }
    } else if (i < b1 || i > b2) {
      if (k % 2 == 0) {
        newCows[i] = cows[i];
      } else {
        newCows[i] = cows[b2 - (i - b1)];
      }
    } else {
      newCows[i] = cows[a2 - (i - a1)];
      newCows[i] = cows[b2 - (i - b1)];
      int saveCows[n];
      for (int i = 0; i < k; i++) {
        for (int i = 0; i < n; i++) {
          saveCows[i] = newCows[i];
        }
        newCows[i] = saveCows[a2 - (i - a1)];
        newCows[i] = saveCows[b2 - (i - b1)];
      }
    }
  }

  for (int i = 0; i < n - 1; i++) {
    cout << newCows[i] << "\n";
  }
  cout << newCows[n - 1];
}

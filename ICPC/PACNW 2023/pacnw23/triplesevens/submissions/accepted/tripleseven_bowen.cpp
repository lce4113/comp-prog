#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  bool allOk = true;
  for (int i = 0; i < 3; i++) {
    bool rowOk = false;
    for (int j = 0; j < n; j++) {
      int d;
      cin >> d;
      if (d == 7) rowOk = true;
    }
    if (!rowOk) allOk = false;
  }
  cout << (allOk ? 777 : 0) << endl;
  return 0;
}

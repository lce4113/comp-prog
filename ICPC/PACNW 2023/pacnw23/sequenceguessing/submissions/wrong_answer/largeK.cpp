#include<iostream>

using namespace std;

int main() {
  srand(42);
  int K = 1000000000;
  cout << K << endl;
  cout.flush();
  while (true) {
    int x;
    cin >> x;
    if (x == -1) {
      for (int i = 0; i < K; i++) {
        cout << i << endl;
        if (i % 1000 == 0) cout.flush();
      }
      cout.flush();
      break;
    }
    else {
      int ans;
      if (x < 100000) ans = x + 1;
      else if (x == 100000) ans = K;
      else ans = rand();
      cout << ans << endl;
      cout.flush();
    }
  }
  return 0;
}

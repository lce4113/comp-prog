#include<iostream>

using namespace std;

int main() {
  srand(42);
  int K = 66668;
  cout << K << endl;
  cout.flush();
  while (true) {
    int x;
    cin >> x;
    if (x == -1) {
      for (int i = 0; i < K; i++) cout << rand() << endl;
      cout.flush();
      break;
    }
    else {
      cout << rand() << endl;
      cout.flush();
    }
  }
  return 0;
}

#include <iostream>

using namespace std;

bool good(int a, int b, int c) {
  for(int i = 0; i < 4; i++) {
    if(a%10 != c%10 && b%10 != c%10) return false;
    a /= 10;
    b /= 10;
    c /= 10;
  }
  return true;
}

int main() {
  int a, b;
  cin >> a >> b;
  int ret = 0;
  for(int i = 0; i < 10000; i++) ret += good(a, b, i);
  cout << ret << "\n";
}
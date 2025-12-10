#include <iostream>
#include <set>

using namespace std;

int main() {
  int n;
  cin >> n;
  set<int> uniqueValues;
  for (int i = 0; i < n; i++) {
    int d;
    cin >> d;
    uniqueValues.insert(d);
  }
  int allWays = 1, distinctWays = 1;
  for (int i = 0; i < 4 - n; i++) {
    allWays *= 6;
    distinctWays *= 6 - n - i;
  }
  int ansA, ansB;
  if (uniqueValues.size() < n) {
    ansA = 0;
    ansB = allWays;
  }
  else {
    ansA = distinctWays;
    ansB = allWays - distinctWays;
  }
  cout << ansA << " " << ansB << endl;
  return 0;
}

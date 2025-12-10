#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

vector<int> sliceAndReverse(vector<int> vec, int a, int b) {
  vector<int> newVec;
  for (int i = 0; i < a; i++) {
    newVec.push_back(vec[i]);
  }
  for (int i = 0; i <= b - a; i++) {
    newVec.push_back(vec[b - i]);
  }
  for (int i = b + 1; i < vec.size(); i++) {
    newVec.push_back(vec[i]);
  }
  return newVec;
}

int main() {
  ifstream fin("swap.in");
  ofstream fout("swap.out");

  int n, k, a1, a2, b1, b2;
  fin >> n >> k >> a1 >> a2 >> b1 >> b2;

  vector<int> cows;
  for (int i = 1; i <= n; i++) {
    cows.push_back(i);
  }

  for (int i = 0; i < k; i++) {
    cows = sliceAndReverse(cows, a1 - 1, a2 - 1);
    cows = sliceAndReverse(cows, b1 - 1, b2 - 1);
  }

  for (int i = 0; i < n - 1; i++) {
    fout << cows[i] << "\n";
  }
  fout << cows[n - 1];
}

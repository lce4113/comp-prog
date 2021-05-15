// HPI 2021: Problem B

#include <bits/stdc++.h>

using namespace std;

int main()
{
  string str;
  getline(cin, str);

  int total = 1, num = 0;
  for (char c : str) {
    if (c == ' ') {
      total++;
    }
    if (c == '.' || c == '!' || c == '?') {
      num++;
    }
  }

  cout << total / num;
}

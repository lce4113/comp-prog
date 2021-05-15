// HPI 2021: Problem F

#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  cin >> n;
  string artist;
  cin >> artist;

  string l;
  getline(cin, l);
  for (int i = 0; i < n; i++) {
    string line;
    getline(cin, line);
    int comma = line.find(',');
    if (line.substr(comma + 2) == artist) {
      cout << line.substr(0, comma) << endl;
    }
  }
}

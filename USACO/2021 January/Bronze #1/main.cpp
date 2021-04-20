// ––– 2020 January: Bronze #1 –––

#include <fstream>
#include <iostream>

using namespace std;

int pos(char a, string alphabet) {
  for (int i = 0; i < 26; ++i) {
    if (a == alphabet[i]) {
      return i;
    }
  }
  return 26;
}

int main() {
  string alphabet;
  string phrase;

  cin >> alphabet >> phrase;

  // cout << alphabet << phrase;
  ifstream fin("cow.in");
  fin >> alphabet >> phrase;

  int n = 0;
  char l, pl;
  int plpos, lpos;
  for (int i = 0; i < phrase.length(); ++i) {
    l = phrase[i];
    lpos = pos(l, alphabet);

    if (i == 0) {
      n++;
      continue;
    }

    if (lpos <= plpos) {
      n++;
    }

    pl = l;
    plpos = lpos;
  }

  cout << n;
}

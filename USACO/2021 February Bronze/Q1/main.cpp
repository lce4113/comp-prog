// ––– 2021 February: Bronze #1 –––

#include <bits/stdc++.h>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
  int n;
  cin >> n;

  map<string, int> zodiacs = {
    { "Ox", 0 },
    { "Tiger", 1 },
    { "Rabbit", 2 },
    { "Dragon", 3 },
    { "Snake", 4 },
    { "Horse", 5 },
    { "Goat", 6 },
    { "Monkey", 7 },
    { "Rooster", 8 },
    { "Dog", 9 },
    { "Pig", 10 },
    { "Rat", 11 }
  };

  map<string, int> cows = { { "Bessie", 0 } };
  for (int i = 0; i < n; i++) {
    string cow1, born, in, pos, zodiac, year, from, cow2;
    cin >> cow1 >> born >> in >> pos >> zodiac >> year >> from >> cow2;

    if (pos == "next") {
      int year = zodiacs[zodiac];
      while (year <= cows[cow2])
        year += 12;
      while (year > cows[cow2] + 12)
        year -= 12;
      cows[cow1] = year;
    } else {
      int year = zodiacs[zodiac];
      while (year >= cows[cow2])
        year -= 12;
      while (year < cows[cow2] - 12)
        year += 12;
      cows[cow1] = year;
    }

    if (cow1 == "Elsie")
      break;
  }

  cout << abs(cows["Elsie"]);
}

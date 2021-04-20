// ––– 2021 February: Bronze #3 –––

#include <bits/stdc++.h>
#include <fstream>
#include <iostream>

using namespace std;

struct dir {
  char dir;
  int x, y;
};

int main()
{
  int n;
  cin >> n;

  for (int j = 0; j < n; j++) {
    string str;
    cin >> str;

    dir dirs[str.size()];
    pair<int, int> pos(0, 0);
    for (int i = 0; i < str.size(); i++) {
      char pole = str[i];

      dir currDir;
      currDir.dir = pole;
      if (pole == 'N') {
        currDir.x = pos.first;
        currDir.y = pos.second + 1;
        pos.second += 2;
      } else if (pole == 'S') {
        currDir.x = pos.first;
        currDir.y = pos.second - 1;
        pos.second -= 2;
      } else if (pole == 'E') {
        currDir.x = pos.first + 1;
        currDir.y = pos.second;
        pos.first += 2;
      } else if (pole == 'W') {
        currDir.x = pos.first - 1;
        currDir.y = pos.second;
        pos.first -= 2;
      }
      dirs[i] = currDir;
    }

    int left = 0, right = 0;
    for (int i = 1; i < str.size(); i++) {
      if (dirs[0].dir == 'N') {
        if (dirs[0].y == dirs[i].y && (dirs[i].dir == 'N' || dirs[i].dir == 'S')) {
          if (dirs[0].x < dirs[i].x)
            right++;
        }
      } else if (dirs[0].dir == 'S') {
        if (dirs[0].y == dirs[i].y && (dirs[i].dir == 'N' || dirs[i].dir == 'S')) {
          if (dirs[0].x > dirs[i].x)
            right++;
        }
      } else if (dirs[0].dir == 'E') {
        if (dirs[0].x == dirs[i].x && (dirs[i].dir == 'E' || dirs[i].dir == 'W')) {
          if (dirs[0].y > dirs[i].y)
            right++;
        }
      } else if (dirs[0].dir == 'W') {
        if (dirs[0].x == dirs[i].x && (dirs[i].dir == 'E' || dirs[i].dir == 'W')) {
          if (dirs[0].y < dirs[i].y)
            right++;
        }
      }
    }

    if (right % 2 == 1)
      cout << "CW";
    else
      cout << "CCW";
    cout << endl;
  }
}

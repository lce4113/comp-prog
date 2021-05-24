#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back
using str = string;
using ll = long long;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int, int>;
using vl = vector<ll, ll>;

int total = 0, u = 0;
str maze[25][25];

bool check(char ttt[3][3])
{
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << ttt[i][j] << ' ';
    }
    cout << endl;
  }
  cout << endl;
  int pos[8][3][2] = {
    { { 0, 0 }, { 0, 1 }, { 0, 2 } },
    { { 1, 0 }, { 1, 1 }, { 1, 2 } },
    { { 2, 0 }, { 2, 1 }, { 2, 2 } },
    { { 0, 0 }, { 1, 0 }, { 2, 0 } },
    { { 0, 1 }, { 1, 1 }, { 2, 1 } },
    { { 0, 2 }, { 1, 2 }, { 2, 2 } },
    { { 0, 0 }, { 1, 1 }, { 2, 2 } },
    { { 2, 2 }, { 1, 1 }, { 0, 0 } },
  };
  for (int i = 0; i < 8; i++) {
    char a = ttt[pos[i][0][0]][pos[i][0][1]];
    char b = ttt[pos[i][1][0]][pos[i][1][1]];
    char c = ttt[pos[i][2][0]][pos[i][2][1]];
    if (a == 'M' && b == 'O' && c == 'O')
      return true;
    if (a == 'O' && b == 'O' && c == 'M')
      return true;
  }
  return false;
}

void move(char ttt[3][3], int bx, int by)
{
  str b = maze[bx][by];
  if (b.at(0) == 'M') {
    ttt[b.at(1) - '0' - 1][b.at(2) - '0' - 1] = 'M';
    maze[bx][by] = 'X';
    if (check(ttt)) {
      total++;
      return;
    }
  } else if (b.at(0) == 'O') {
    ttt[b.at(1) - '0' - 1][b.at(2) - '0' - 1] = 'O';
    maze[bx][by] = 'X';
    if (check(ttt)) {
      total++;
      return;
    }
  } else if (b == "...") {
    maze[bx][by] = 'X';
  }

  int dx[] = { 0, 0, 1, -1 };
  int dy[] = { 1, -1, 0, 0 };

  for (int i = 0; i < 4; i++) {
    int x = dx[i];
    int y = dy[i];
    str newb = maze[bx + x][by + y];
    char copyTTT[3][3];
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        copyTTT[i][j] = ttt[i][j];
      }
    }
    if (newb.at(0) == 'M' || newb.at(0) == 'O' || newb.at(0) == '.') {
      move(copyTTT, bx + x, by + y);
    }
  }
}

int main()
{
  int n, bx, by;
  cin >> n;

  for (int i = 0; i < n; i++) {
    str row;
    cin >> row;
    for (int j = 0; j < n; j++) {
      char a = row.at(3 * j), b = row.at(3 * j + 1), c = row.at(3 * j + 2);
      switch (a) {
      case 'B':
        bx = i;
        by = j;
        maze[i][j] = "...";
        break;
      default:
        maze[i][j] = string() + a + b + c;
        break;
      }
    }
  }
  char ttt[3][3] = {
    { '.', '.', '.' },
    { '.', '.', '.' },
    { '.', '.', '.' }
  };
  move(ttt, bx, by);
  cout << total;
}

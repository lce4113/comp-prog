// Round #711: Problem B

#include <bits/stdc++.h>

using namespace std;

int smallest(vi vec, int len, int max)
{
  int pos = -1;
  for (int i = 0; i < len; i++) {
    if (vec[i] <= max && (pos == -1 || vec[i] > vec[pos])) {
      pos = i;
    }
  }
  return pos;
}

int main()
{
  int m;
  cin >> m;

  for (int j = 0; j < m; j++) {
    int n, w, spaceLeft;
    cin >> n >> w;
    spaceLeft = w;

    vi rects;
    for (int i = 0; i < n; i++) {
      int rect;
      cin >> rect;
      rects.push_back(rect);
    }

    int h = 0;
    for (int i = 0; i < n; i++) {
      int pos = smallest(rects, n, spaceLeft);
      if (pos == -1) {
        h++;
        spaceLeft = w;
        i++;
        continue;
      }
      spaceLeft -= rects[pos];
      rects.erase(rects.begin() + pos);
    }

    cout << endl
         << h;
  }
}

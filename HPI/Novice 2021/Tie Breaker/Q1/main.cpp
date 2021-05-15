// HPI 2021: Problem B

#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
#define f first
#define s second

bool compare(pi point1, pi point2)
{
  double angle1 = atan((double)point1.f / point1.s);
  double angle2 = atan((double)point2.f / point2.s);
  return angle1 > angle2;
}

int main()
{
  int n, m;
  cin >> n >> m;

  pi points[n];
  for (int i = 0; i < n; i++) {
    pi point;
    cin >> point.f >> point.s;
    points[i] = point;
  }

  sort(points, points + n, compare);

  double angles[n], lengths[n];
  for (int i = 0; i < n; i++) {
    int x = points[i].f;
    int y = points[i].s;
    angles[i] = atan((double)y / x);
    lengths[i] = sqrt(pow(x, 2) + pow(y, 2));
  }

  double angle1 = angles[1], angle2 = angles[0];
  double currTotal = sin(angles[1] - angles[0]) * lengths[1];
  double total = sin(angle2) * lengths[0] + currTotal;

  for (int i = 2; i < n; i++) {
    double currTotal1 = sin(angles[i] - angle2) * lengths[i];
    double currTotal2 = sin(angles[i] - angle1) * lengths[i];
    double total1 = total - currTotal + currTotal1;
    double total2 = total + currTotal2;
    if (total1 <= total2) {
      angle1 = angles[i];
      total = total1;
      currTotal = currTotal1;
    } else {
      angle1 = angles[i];
      angle2 = angle1;
      total = total2;
      currTotal = currTotal2;
    }
  }

  cout << round(total * 1000) / 1000;
}

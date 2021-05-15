// HPI 2021 Practice: Problem A

#include <bits/stdc++.h>

using namespace std;

void binary(vector<int>& vec, int target, int low, int high)
{
  if (high - low <= 1) {
    if (vec[low] == target) {
      vec.erase(vec.begin() + low);
    } else {
      vec.erase(vec.begin() + low + 1);
    }
    return;
  }
  int middle = (low + high) / 2;
  if (target == vec[middle]) {
    binary(vec, target, middle, middle);
  } else if (target > vec[middle]) {
    binary(vec, target, middle, high);
  } else {
    binary(vec, target, low, middle);
  }
}

int main()
{
  int n;
  cin >> n;

  vector<int> contests;
  for (int i = 0; i < n; i++) {
    int contest;
    cin >> contest;
    contests.push_back(contest);
  }
  sort(contests.begin(), contests.end());

  int days = 0;
  for (int i = 1; i <= n; i++) {
    if (contests.back() < i) {
      break;
    }
    binary(contests, i, 0, contests.size());
    days++;
  }

  cout << days;
}

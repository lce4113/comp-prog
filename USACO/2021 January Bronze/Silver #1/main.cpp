// ––– 2021 January: Silver #1 –––

#include <bits/stdc++.h>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;

  pair<int, int> swaps[k];
  for (int i = 0; i < k; i++) {
    pair<int, int> swap;
    cin >> swap.first;
    cin >> swap.second;
    swaps[i] = swap;
  }

  set<int> positions[n];
  int nums[n];
  for (int i = 0; i < n; i++) {
    nums[i] = i + 1;
    positions[i].insert(i + 1);
  }

  int temp;
  for (int j = 0; j < k; j++) {
    for (int i = 0; i < k; i++) {
      pair<int, int> swap = swaps[i];

      temp = nums[swap.first];
      nums[swap.first] = nums[swap.second];
      nums[swap.second] = temp;

      positions[nums[swap.first - 1] - 1].insert(swap.first);
      positions[nums[swap.second - 1] - 1].insert(swap.second);
    }
  }

  cout << positions[0].size();
  for (int i = 1; i < n; i++) {
    cout << endl
         << positions[i].size();
  }
}

// HPI 2021: Problem D

#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  cin >> n;
  cout << n;
  string nums;
  getline(cin, nums);

  for (char c : nums) {
    cout << c;
  }

  int start = 0, end = 0;
  for (int i = 0; i < n - 4; i++) {
    if (nums[i] == '0' && nums[i + 1] == '1' && nums[i + 2] == '2' && nums[i + 3] == '3' && nums[i + 4] == '4') {
      start++;
    } else if (nums[i] == '5' && nums[i + 1] == '6' && nums[i + 2] == '7' && nums[i + 3] == '8' && nums[i + 4] == '9') {
      end++;
    }
  }

  cout << start << endl
       << end << endl;
  cout << start * end;
}

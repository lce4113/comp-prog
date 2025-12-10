#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, d;
  cin >> n >> d;
  vector<int> pitch(n, 0);
  for (int i = 0; i < n; i++) cin >> pitch[i];
  sort(pitch.begin(), pitch.end());
  int lastPitch = -1;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (lastPitch == -1 || pitch[i] - lastPitch > d) {
      ans++;
      lastPitch = pitch[i];
    }
  }
  cout << ans << endl;
  return 0;
}

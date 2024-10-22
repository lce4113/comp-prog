// USACO 2023 December Silver: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
  int T, C;
  cin >> T >> C;
  set<int> targets;
  for (int i = 0; i < T; i++) {
    int t;
    cin >> t;
    targets.insert(t);
  }
  string commands;
  cin >> commands;

  // store forward
  vector<int> pos(C);
  int curr_pos = 0;
  for (int i = 0; i < C; i++) {
    if (commands[i] == 'R') curr_pos++;
    if (commands[i] == 'L') curr_pos--;
    pos[i] = curr_pos;
  }

  // store backward
  vector<int> a(C + 1, 0), b(C + 1, 0), d(C + 1, 0), e(C + 1, 0);
  set<int> remaining_targets_a = targets;
  set<int> remaining_targets_b = targets;
  set<int> remaining_targets_d = targets;
  set<int> remaining_targets_e = targets;
  for (int i = C - 1; i >= 0; i--) {
    a[i] = a[i + 1];
    b[i] = b[i + 1];
    d[i] = d[i + 1];
    e[i] = e[i + 1];
    if (commands[i] == 'F') {
      a[i] += remaining_targets_a.count(pos[i] - 2);
      b[i] += remaining_targets_b.count(pos[i] - 1);
      d[i] += remaining_targets_d.count(pos[i] + 1);
      e[i] += remaining_targets_e.count(pos[i] + 2);
      remaining_targets_a.erase(pos[i] - 2);
      remaining_targets_b.erase(pos[i] - 1);
      remaining_targets_d.erase(pos[i] + 1);
      remaining_targets_e.erase(pos[i] + 2);
    }
  }

  for (auto x : targets) cout << x << ' ';
  cout << '\n';
  for (auto x : pos) cout << x << ' ';
  cout << '\n';
  for (auto x : a) cout << x << ' ';
  cout << '\n';
  for (auto x : b) cout << x << ' ';
  cout << '\n';
  for (auto x : d) cout << x << ' ';
  cout << '\n';
  for (auto x : e) cout << x << ' ';
  cout << '\n';

  // store forward
  int curr_score = 0, ans = 0;
  set<int> remaining_targets = targets;
  for (int i = 0; i < C; i++) {
    int curr_pos = pos[i];
    cout << commands[i] << ' ';
    if (commands[i] == 'F') {
      int hit = remaining_targets.count(curr_pos);
      cout << curr_score << b[i + 1] << ' ';
      cout << curr_score << d[i + 1] << ' ';
      ans = max(ans, curr_score + b[i + 1]);
      ans = max(ans, curr_score + d[i + 1]);
      curr_score += hit;
      remaining_targets.erase(curr_pos);
    }
    if (commands[i] == 'R') {
      int hit = remaining_targets.count(curr_pos - 1);
      ans = max(ans, curr_score + a[i + 1]);
      ans = max(ans, curr_score + hit + b[i + 1]);
      cout << curr_score << a[i + 1] << ' ';
      cout << curr_score << hit << b[i + 1] << ' ';
    }
    if (commands[i] == 'L') {
      int hit = remaining_targets.count(curr_pos + 1);
      ans = max(ans, curr_score + e[i + 1]);
      ans = max(ans, curr_score + hit + d[i + 1]);
      cout << curr_score << e[i + 1] << ' ';
      cout << curr_score << hit << d[i + 1] << ' ';
    }
    ans = max(ans, curr_score);
    cout << '\n';
  }

  cout << ans << '\n';
}

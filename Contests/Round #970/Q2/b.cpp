// CodeForces Round #970: Problem B

#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	string s,S="";
	cin >> s;
	int x = sqrt(n);
	if (x*x != n) {
		cout << "No\n";
		return;
	}
	for (int i = 0; i < x; i++) {
		S += "1";
	}
	for (int i = 2; i < x; i++) {
		S += "1";
		for (int j = 2; j < x; j++) {
			S += "0";
		}
		S += "1";
	}
	for (int i = 0; i < x; i++) {
		S += "1";
	}
	for (int i = 0; i < n; i++) {
		if (S[i] != s[i]) {
			cout << "No\n";
			return;
		}
	}
	cout << "Yes\n";
}

int32_t main() {
	int t;
	cin >> t;
	while (t--) solve();
}
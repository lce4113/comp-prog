// CodeForces Round #970: Problem A

#include <bits/stdc++.h>
using namespace std;

void solve() {
	int a, b;
	cin >> a >> b;
	if (a%2) {
		cout << "NO\n";
		return;
	}
	if (b%2 && a<2) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
}

int32_t main() {
	int t;
	cin >> t;
	while (t--) solve();
}
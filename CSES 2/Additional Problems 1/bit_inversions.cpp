// CSES Additional Problems I: Bit Inversions

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    string a;
    cin >> a;
    int n = a.size();
    set<int> ends({0});
    multiset<int> L;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] != a[i + 1]) {
            L.insert(i + 1 - *ends.rbegin());
            ends.insert(i + 1);
        }
    }
    L.insert(n - *ends.rbegin());
    ends.insert(n);

    int q;
    cin >> q;
    while (q--) {
        int p;
        cin >> p;
        p--;
        if (p != n - 1) {
            if (a[p] == a[p + 1]) {
                auto next = ends.lower_bound(p + 1);
                auto prev = next;
                prev--;
                L.erase(L.lower_bound(*next - *prev));
                L.insert(*next - (p + 1));
                L.insert((p + 1) - *prev);
                ends.insert(p + 1);
            } else {
                ends.erase(p + 1);
                auto next = ends.lower_bound(p + 1);
                auto prev = next;
                prev--;
                L.erase(L.lower_bound(*next - (p + 1)));
                L.erase(L.lower_bound((p + 1) - *prev));
                L.insert(*next - *prev);
            }
        }
        if (p != 0) {
            if (a[p - 1] == a[p]) {
                auto next = ends.lower_bound(p);
                auto prev = next;
                prev--;
                L.erase(L.lower_bound(*next - *prev));
                L.insert(*next - p);
                L.insert(p - *prev);
                ends.insert(p);
            } else {
                ends.erase(p);
                auto next = ends.lower_bound(p);
                auto prev = next;
                prev--;
                L.erase(L.lower_bound(*next - p));
                L.erase(L.lower_bound(p - *prev));
                L.insert(*next - *prev);
            }
        }
        a[p] = a[p] == '0' ? '1' : '0';

        // for (auto x : L) cout << x << ' ';
        // cout << '\n';
        cout << *L.rbegin() << ' ';
    }
    cout << '\n';
}
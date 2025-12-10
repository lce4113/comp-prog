// Codeforces Educational Round 174
// Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MOD = 1e9 + 7;
const int P = 998244353;

int binexp(int a, int b = MOD - 2) {
    int ans = 1;
    for (; b; a *= a, a %= MOD) {
        if (b % 2) ans *= a, ans %= MOD;
        b /= 2;
    }
    return ans;
}

int H(int h, int v) { return (((h * P) % MOD) + v) % MOD; }
int H_inv(int h, int hi, int len) {
    return (h - (hi * binexp(P, len)) % MOD + MOD) % MOD;
}
int Hr(vector<int> pfs, int l, int r) { return H_inv(pfs[r], pfs[l], r - l); }

bool pal(string b) {
    int N = b.size();
    for (int i = 0; i < N / 2; i++) {
        if (b[i] != b[N - 1 - i]) return false;
    }
    return true;
}

string a, sa;
int n;

pair<int, int> solve() {
    // cin >> a;
    if (pal(a)) return {-1, -2};

    int l = 0;
    while (l < n / 2 && a[l] == a[n - 1 - l]) l++;
    n -= 2 * l;
    a = a.substr(l, n);

    // -- THING 1 --

    vector<int> hpfs(1, 0), hipfs(1, 0);
    for (auto x : a) hpfs.push_back(H(hpfs.back(), (x - 'a')));
    reverse(a.begin(), a.end());
    for (auto x : a) hipfs.push_back(H(hipfs.back(), (x - 'a')));
    reverse(a.begin(), a.end());

    // for (auto x : hpfs) cout << x << ' ';
    // cout << '\n';
    // for (auto x : hipfs) cout << x << ' ';
    // cout << '\n';

    int R = n / 2 - 1;
    while (R >= 0 && a[R] == a[n - 1 - R]) R--;
    R++;

    if (Hr(hpfs, 0, R) == Hr(hpfs, n - R, n)) {
        return {l, l + R - 1};
    }

    int r = n / 2;
    while (r > 0 && (Hr(hpfs, 0, r) != Hr(hpfs, r, 2 * r) ||
                     Hr(hpfs, 2 * r, n / 2 + r) != Hr(hipfs, 0, n / 2 - r)))
        r--;
    int ans = n - r;
    pair<int, int> ansp = {l + r, l + n - 1};

    r = n / 2;
    while (r > 0 && (Hr(hpfs, n - r, n) != Hr(hpfs, n - 2 * r, n - r) ||
                     Hr(hpfs, n / 2 - r, n - 2 * r) != Hr(hipfs, n / 2 + r, n)))
        r--;
    if (n - r < ans) ans = n - r, ansp = {l, l + n - r - 1};

    // cout << n / 2 << ' ' << l << ' ' << r << '\n';
    return ansp;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    // int t = 1;
    // cin >> t;
    // while (t--) {
    //     cin >> a;
    //     n = a.size();
    //     auto ans = solve();
    //     cout << ans.f << ' ' << ans.s << '\n';
    // }

    // "aabbaa"
    // "aaabba" -> "aaABBa"
    // "abcabcdeed"
    // "deedabcabc"
    // "aAABBA"
    // "aaabba" -> "aAABBA"
    // "aAABBA"
    n = 12;
    for (char i1 = 'a'; i1 - 'a' < 5; i1++) {
        for (char i2 = 'a'; i2 - 'a' < 5; i2++) {
            for (char i3 = 'a'; i3 - 'a' < 5; i3++) {
                for (char i4 = 'a'; i4 - 'a' < 5; i4++) {
                    for (char i5 = 'a'; i5 - 'a' < 5; i5++) {
                        for (char i6 = 'a'; i6 - 'a' < 5; i6++) {
                            for (int l = 0; l < n; l++) {
                                for (int r = l; r < n; r++) {
                                    a = "", n = 12;
                                    a += i1, a += i2, a += i3, a += i4, a += i5,
                                        a += i6;
                                    a += i6, a += i5, a += i4, a += i3, a += i2,
                                        a += i1;
                                    cout << a << '\n';
                                    // reverse
                                    string b = a.substr(l, r - l + 1);
                                    reverse(b.begin(), b.end());
                                    for (int i = l; i <= r; i++)
                                        a[i] = b[i - l];
                                    sa = a;
                                    cout << a << '\n';
                                    // solve
                                    auto ans = solve();
                                    if (ans.s - ans.f + 1 > r - l + 1) {
                                        cout << ans.f << ' ' << ans.s << '\n';
                                        cout << "ohno1\n";
                                        return 0;
                                    }
                                    cout << l << ' ' << r << ' ' << ans.f << ' '
                                         << ans.s << '\n';
                                    // reset vars
                                    a = sa, n = 12;
                                    // reverse again
                                    if (ans.f != -1) {
                                        b = a.substr(ans.f, ans.s - ans.f + 1);
                                        reverse(b.begin(), b.end());
                                        for (int i = ans.f; i <= ans.s; i++)
                                            a[i] = b[i - ans.f];
                                    }
                                    cout << a << '\n';
                                    // check palindrome
                                    if (!pal(a)) {
                                        cout << "ohno2\n";
                                        return 0;
                                    }
                                    cout << '\n';
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
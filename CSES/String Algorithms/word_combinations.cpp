// CSES String Algorithms: Word Combinations

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 5000;
vector<int> dp(MAXN + 1, 0);
string a;
int n;

struct Trie {
    vector<vector<int>> t(MAXL, vector<int>) vector<Trie *> nxt;
    bool term = 0;
    Trie() : nxt(26) {}
    void add(string &b, int i = 0) {
        int m = b.size();
        if (i == m) {
            term = 1;
            return;
        }
        int c = b[i] - 'a';
        if (!nxt[c]) nxt[c] = new Trie();
        nxt[c]->add(b, i + 1);
    }
    void calc(int i, int val) {
        // cout << i << ' ' << val << '\n';
        if (term) dp[i] += val, dp[i] %= MOD;
        if (i == n) return;
        int c = a[i] - 'a';
        if (!nxt[c]) return;
        nxt[c]->calc(i + 1, val);
    }
};

int32_t main() {
    cin >> a;
    n = a.size();
    int k;
    cin >> k;
    Trie *T = new Trie();
    while (k--) {
        string b;
        cin >> b;
        T->add(b);
    }
    dp[0] = 1;
    for (int i = 0; i < n; i++) T->calc(i, dp[i]);
    cout << dp[n] << '\n';
}
// CSES Geometry: Area of Rectangles

#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Node {
    Node *L, R;
    int lo, hi, mid;
    int cnt = 0, lazy = 0;
    Node(int l, int r) : lo(l), hi(r) {
        mid = (lo + hi) / 2;
        if (hi - lo == 1) return;
        L = new Node(lo, mid);
        R = new Node(mid, hi);
    }
    void u(int l, int r) {
        if (lo >= r || hi <= l) return;
        if (l <= lo && hi <= r) {
            lazy++;
            return;
        }
        push();
        if (L) L->u(l, r);
        if (R) R->u(l, r);
        cnt = L->cnt + R->cnt;
    }
};

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
}
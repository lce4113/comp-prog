// CSES Range Queries: Range Queries and Copies

#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, q;

struct Node {
    Node *L, *R;
    int lo, hi, mid, tot = 0, ref = 1;
    Node(int _lo, int _hi) : lo(_lo), hi(_hi), mid((lo + hi) / 2) {
        if (hi - lo == 1) return;
        L = new Node(lo, mid);
        R = new Node(mid, hi);
    }
    Node(Node *o) {
        L = o->L, R = o->R;
        if (L) L->ref++;
        if (R) R->ref++;
        lo = o->lo, hi = o->hi, mid = o->mid, tot = o->tot;
    }
    void u(int i, int x) {
        if (hi - lo == 1) {
            tot = x;
            return;
        }
        if (i < mid) {
            Node *L2 = new Node(L);
            swap(L2, L);
            L2->ref--;
            if (L2->ref == 0) delete L2;
            L->u(i, x);
        } else {
            Node *R2 = new Node(R);
            swap(R2, R);
            R2->ref--;
            if (R2->ref == 0) delete R2;
            R->u(i, x);
        }
        tot = (L ? L->tot : 0) + (R ? R->tot : 0);
    }
    int q(int l, int r) {
        if (hi <= l || lo >= r) return 0;
        if (l <= lo && hi <= r) return tot;
        return (L ? L->q(l, r) : 0) + (R ? R->q(l, r) : 0);
    }
    ~Node() {
        if (L && --L->ref == 0) delete L;
        if (R && --R->ref == 0) delete R;
    }
};

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> q;
    vector<Node *> trees;
    trees.push_back(new Node(0, n));
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        trees[0]->u(i, x);
    }
    while (q--) {
        int tp, k;
        cin >> tp >> k;
        k--;
        if (tp == 1) {
            int a, x;
            cin >> a >> x;
            a--;
            trees[k]->u(a, x);
        } else if (tp == 2) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            cout << trees[k]->q(a, b + 1) << '\n';
        } else {
            trees.push_back(new Node(trees[k]));
        }
    }
}
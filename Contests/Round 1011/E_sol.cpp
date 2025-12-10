#include <cstdio>

using namespace std;

const int N = 1e4 + 5;
const int C = 1e6 + 5;

int n;
int a[N], b[N];
int cnt[C];
long long s;

bool check(int k) {
    for (int i = 1; i <= n; i++) cnt[a[i] % k]++;
    for (int i = 1; i <= n; i++)
        if (--cnt[b[i]] < 0) {
            cnt[b[i]] = 0;
            for (int i = 1; i <= n; i++) cnt[a[i] % k] = 0;
            return 0;
        }
    return 1;
}

void solve() {
    scanf("%d", &n);
    s = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        s += a[i];
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
        s -= b[i];
    }
    if (s == 0) {
        printf("%d\n", check(0xc0ffee) ? 0xc0ffee : -1);
        return;
    }
    for (int i = 1; 1ll * i * i <= s; i++)
        if (s % i == 0) {
            if (check(i)) {
                printf("%d\n", i);
                return;
            }
            if (i < C && check(s / i)) {
                printf("%d\n", (int)(s / i));
                return;
            }
        }
    printf("-1\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
    return 0;
}
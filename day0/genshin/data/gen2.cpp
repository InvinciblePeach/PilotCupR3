#include <bits/stdc++.h>
#include <format>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
const int MAXN = 2e5 + 10, MAXV = (1 << 30) - 1;
int f[MAXN], w[MAXN], siz[MAXN], tot, L, R;
int lc[MAXN], rc[MAXN], fa[MAXN];

int build(int siz, int val, int dep, int flag) {
    // cerr << siz << '\n';
    if (siz <= 0) return 0;
    int p = ++tot;
    ::siz[p] = siz;
    if (dep == 2) L = p - 1;
    f[p] = val;
    if (flag) {
        int val1 = val;
        if (dep % 10000 == 0) val1 &= rnd();
        lc[p] = build(siz - 1, val1, dep + 1, max(0, flag - 1));
        if (lc[p]) fa[lc[p]] = p;
        return p;
    }
    int tmp1 = siz >> 1;
    int tmp2 = siz - (++tmp1) - 1;
    if (siz == 2) tmp1 = 1, tmp2 = 0;
    if (siz == 1) return p;
    int val1 = val, val2 = val;
    if (dep % 100 == 0) val1 &= rnd(), val2 ^= val1;
    lc[p] = build(tmp1, val1, dep + 1, 0);
    rc[p] = build(tmp2, val2, dep + 1, 20);
    if (lc[p]) fa[lc[p]] = p;
    if (rc[p]) fa[rc[p]] = p;
    return p;
}

int rand(int l, int r) { return rnd() % (r - l + 1) + l; }

int rand(int l, int r, int len) {
    int res = 0;
    while (__builtin_popcount(res) < len) res = rnd() % (r - l + 1) + l;
    return rnd() % (r - l + 1) + l;
}

void work(int n, int q) {
    cerr << n << ' ' << q << ' ';
    build(n, rnd() & MAXV, 1, 0);
    for (int i = 1; i <= n; i++) w[i] = rnd() & f[i];
    cout << n << ' ' << q << '\n';
    for (int i = 1; i <= n; i++) cout << w[i] << " \n"[i == n];
    for (int i = 1; i <= n; i++) {
        // cout << fa[i] << ' ' << i << '\n';
        if (lc[i]) cout << i << ' ' << lc[i] << '\n';
        if (rc[i]) cout << i << ' ' << rc[i] << '\n';
    }
    assert(tot == n);
    R = tot;
    cerr << L << ' ' << R << '\n';
    while (q-- > 0) {
        static int op, x, y;
        op = rand(1, 2000);
        if (op == 1) {
            x = rand(1, n, 14);
            y = rnd() & f[x];
            cout << "1 " << x << ' ' << y << '\n';
        } else {
            if (rand(1, 50) != 1) {
                cout << "2 " << L << ' ' << n << ' ' << (rnd() & MAXV) << '\n';
            } else {
                // int rt = rand(20000, L);
                // // cerr << rt << ' ' << siz[rt] << '\n';
                // x = rand(rt, rt + siz[rt] - 1);
                // y = rt + siz[rt] >= L ? L : rand(rt + siz[rt], L);
                x = rand(1, n), y = rand(1, n);
                cout << "2 " << x << ' ' << y << ' ' << (rnd() & MAXV) << '\n';
            }
        }
    }
}

signed main() {
    for (int i = 5; i <= 5; i++) {
        string tmp = format("5-{}.in", i);
        freopen(tmp.c_str(), "w", stdout);
        L = R = tot = 0;
        work(rand(1.99e5, 2e5), 2e5);
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
const int MAXN = 1e5 + 10, MAXV = 80;
int n, q, w[MAXN], b[MAXN], top[MAXN], fa[MAXN], siz[MAXN], son[MAXN], fa[MAXN];
int tot, dfn[MAXN], id[MAXN];
vector<int> g[MAXN];

struct Fenwick {
    int t[MAXN];

    constexpr int lowbit(const int &x) { return x & -x; }

    void add(int x, int val) {
        for (; x <= n; x += lowbit(x)) t[x] ^= val;
    }

    int query(int x) {
        int res = 0;
        for (; x; x -= lowbit(x)) res ^= t[x];
        return res;
    }

    int query(int l, int r) { return query(r) ^ query(l - 1); }
} val, b[MAXV];

void dfs1(int u) {
    b[u] = w[u] ^ w[fa[u]];
    siz[u] = 1;
    for (auto v : g[u]) {
        if (v == fa[u]) continue;
        fa[v] = u;
        dfs1(v);
        if (siz[v] > siz[son[u]]) son[u] = v;
        siz[u] += siz[v];
    }
}

void dfs2(int u, int top) {
    dfn[id[u] = ++tot] = u;
    val.add(id[u], w[u]);
    ::top[u] = top;
    if (son[u]) dfs2(son[u], top);
    for (auto v : g[u]) {
        if (v == fa[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].emplace_back(v), g[v].emplace_back(u);
    }
    dfs1(1), dfs2(1, 1);

    return 0;
}
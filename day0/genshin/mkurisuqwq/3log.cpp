#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
const int MAXN = 2e5 + 10, MAXV = 50;
int n, q, w[MAXN], b[MAXN], top[MAXN], fa[MAXN], siz[MAXN], son[MAXN], dep[MAXN];
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
} val, t[MAXV];
bitset<MAXN> vis[MAXV];

struct LB {
    int a[32];

    void clear() { memset(a, 0, sizeof(a)); }

    void insert(int x) {
        for (int i = 31; ~i; i--) {
            if (x >> i & 1) {
                if (!a[i]) {
                    a[i] = x;
                    break;
                }
                x ^= a[i];
            }
        }
    }

    int query(int val) {
        for (int i = 31; ~i; i--) {
            val = max(val, val ^ a[i]);
        }
        return val;
    }
} ans;

void dfs1(int u) {
    b[u] = w[u] ^ w[fa[u]];
    siz[u] = 1;
    for (auto v : g[u]) {
        if (v == fa[u]) continue;
        fa[v] = u, dep[v] = dep[u] + 1;
        dfs1(v);
        if (siz[v] > siz[son[u]]) son[u] = v;
        siz[u] += siz[v];
    }
}

void dfs2(int u, int top) {
    dfn[id[u] = ++tot] = u;
    val.add(id[u], b[u]);
    for (int i = 0; i < MAXV; i++)
        if (vis[i][u] = (rnd() & 1)) t[i].add(id[u], b[u]);
    ::top[u] = top;
    if (son[u]) dfs2(son[u], top);
    for (auto v : g[u]) {
        if (v == fa[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}

int lca(int u, int v) {
    while (top[u] ^ top[v]) {
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
        u = fa[top[u]];
    }
    if (dep[u] > dep[v]) swap(u, v);
    return u;
}

int query(int u) {
    int res = 0;
    while (u) {
        res ^= val.query(id[top[u]], id[u]);
        u = fa[top[u]];
    }
    return res;
}

int query(int u, int id) {
    int res = 0;
    while (u) {
        res ^= t[id].query(::id[top[u]], ::id[u]);
        u = fa[top[u]];
    }
    return res;
}

int query(int u, int v, int id) { return query(u, id) ^ query(v, id); }

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].emplace_back(v), g[v].emplace_back(u);
    }
    dep[1] = 1;
    dfs1(1), dfs2(1, 1);
    while (q-- > 0) {
        static int op, x, y, z;
        cin >> op >> x >> y;
        if (op == 1) {
            val.add(id[x], y);
            for (int i = 0; i < MAXV; i++) {
                if (vis[i][x]) t[i].add(id[x], y);
            }
        } else {
            cin >> z;
            ans.clear();
            for (int i = 0; i < MAXV; i++) ans.insert(query(x, y, i));
            ans.insert(query(lca(x, y)));
            cout << ans.query(z) << '\n';
        }
    }

    return 0;
}
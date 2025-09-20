#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
const int MAXN = 2e5 + 10, MAXV = 50;
int n, q, w[MAXN], b[MAXN], siz[MAXN], fa[MAXN], son[MAXN], top[MAXN], dep[MAXN];
int st[MAXN], sum[MAXN], tot;
vector<int> g[MAXN];

void dfs1(int u, int fa) {
    ::fa[u] = fa;
    dep[u] = dep[fa] + 1;
    b[u] = w[u] ^ w[fa];
    siz[u] = 1;
    for (auto v : g[u]) {
        if (v == fa) continue;
        dfs1(v, u);
        siz[u] += siz[v];
        if (siz[v] > siz[son[u]]) son[u] = v;
    }
}

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

namespace gbt {
    int lc[MAXN], rc[MAXN], fa[MAXN];
    bitset<MAXV> vis[MAXN];
    int sum[MAXN][MAXV];

    int build(int l, int r) {
        if (l > r) return 0;
        int mid = lower_bound(::sum + l, ::sum + r + 1, (::sum[l - 1] + ::sum[r]) >> 1) - ::sum, p = st[mid];
        for (int i = 0; i < MAXV; i++)
            if (vis[p][i]) sum[p][i] = b[p];
        lc[p] = build(l, mid - 1);
        rc[p] = build(mid + 1, r);
        if (lc[p]) fa[lc[p]] = p;
        if (rc[p]) fa[rc[p]] = p;
        for (int i = 0; i < MAXV; i++) sum[p][i] ^= sum[lc[p]][i] ^ sum[rc[p]][i];
        return p;
    }

    int dfs2(int u, int fa, int top) {
        vis[u][0] = 1;
        for (int i = 1; i < MAXV; i++) vis[u][i] = rnd() & 1;
        ::top[u] = top;
        int rt = 0;
        st[++tot] = u;
        ::sum[tot] = ::sum[tot - 1] + siz[u] - siz[son[u]];
        if (son[u])
            rt = dfs2(son[u], u, top);
        else {
            rt = build(1, tot);
            tot = 0;
            return rt;
        }
        for (auto v : g[u]) {
            if (v == fa || v == son[u]) continue;
            gbt::fa[dfs2(v, u, v)] = u;
        }
        return rt;
    }

    void modify(int p, int val) {
        const auto &vis = gbt::vis[p];
        while (p) {
            for (int i = 0; i < MAXV; i++)
                if (vis[i]) sum[p][i] ^= val;
            if (p == lc[fa[p]] || p == rc[fa[p]])
                p = fa[p];
            else
                break;
        }
    }

    int query(int p) {
        bool flag = true;
        int res = 0;
        while (p) {
            if (flag) res ^= sum[p][0] ^ sum[rc[p]][0];
            flag = (p != lc[fa[p]]);
            p = fa[p];
        }
        ans.insert(res);
        return res;
    }

    int res[MAXV];
    void query(int u, int v) {
        bool flag = true;
        memset(res, 0, sizeof(res));
        while (u) {
            if (flag)
                for (int i = 0; i < MAXV; i++) res[i] ^= sum[u][i] ^ sum[rc[u]][i];
            flag = (u != lc[fa[u]]);
            u = fa[u];
        }
        flag = true;
        while (v) {
            if (flag)
                for (int i = 0; i < MAXV; i++) res[i] ^= sum[v][i] ^ sum[rc[v]][i];
            flag = (v != lc[fa[v]]);
            v = fa[v];
        }
        for (int i = 0; i < MAXV; i++) ans.insert(res[i]);
    }
} // namespace gbt

int lca(int u, int v) {
    while (top[u] ^ top[v]) {
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
        u = fa[top[u]];
    }
    if (dep[u] > dep[v]) swap(u, v);
    return u;
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
    dfs1(1, 0), gbt::dfs2(1, 0, 1);
    while (q-- > 0) {
        static int op, x, y, z;
        cin >> op >> x >> y;
        if (op == 1) {
            gbt::modify(x, y);
        } else {
            cin >> z;
            ans.clear();
            gbt::query(x, y);
            gbt::query(lca(x, y));
            cout << ans.query(z) << '\n';
        }
    }
    return 0;
}
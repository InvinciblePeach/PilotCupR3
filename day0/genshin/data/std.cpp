#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
const int MAXN = 1e5 + 10, MAXV = 50;
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

void dfs2(int u, int fa, int top) {
    ::top[u] = top;
    if (son[u]) dfs2(son[u], u, top);
    for (auto v : g[u]) {
        if (v == fa || v == son[u]) continue;
        dfs2(v, u, v);
    }
}

struct GBT {
    bitset<MAXN> vis;
    struct Node {
        int lc, rc, siz, sum, fa;
    } t[MAXN];

#define lc(p) t[p].lc
#define rc(p) t[p].rc

    int build(int l, int r) {
        if (l > r) return 0;
        int mid = lower_bound(sum + l, sum + r + 1, (sum[l] + sum[r]) >> 1) - sum, p = st[mid];
        if (vis[p]) t[p].sum = b[p];
        lc(p) = build(l, mid - 1);
        rc(p) = build(mid + 1, r);
        if (lc(p)) t[lc(p)].fa = p;
        if (rc(p)) t[rc(p)].fa = p;
        t[p].sum ^= t[lc(p)].sum ^ t[rc(p)].sum;
        return p;
    }

    int dfs2(int u, int fa) {
        int rt = 0;
        st[++tot] = u;
        sum[tot] = sum[tot - 1] + siz[u] - siz[son[u]];
        if (son[u])
            rt = dfs2(son[u], u);
        else {
            rt = build(1, tot);
            tot = 0;
            return rt;
        }
        for (auto v : g[u]) {
            if (v == fa || v == son[u]) continue;
            t[dfs2(v, u)].fa = u;
        }
        return rt;
    }

    void modify(int p, int val) {
        while (p) {
            t[p].sum ^= val;
            if (p == lc(t[p].fa) || p == rc(t[p].fa))
                p = t[p].fa;
            else
                break;
        }
    }

    int query(int p) {
        bool flag = true;
        int res = 0;
        while (p) {
            if (flag) res ^= t[p].sum ^ t[rc(p)].sum;
            flag = (p != lc(t[p].fa));
            p = t[p].fa;
        }
        return res;
    }

    int query(int u, int v) { return query(u) ^ query(v); }
} val, t[MAXV];

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
    dfs1(1, 1);
    val.vis.set();
    val.dfs2(1, 1);
    for (int k = 0; k < MAXV; k++) {
        for (int i = 1; i <= n; i++) t[k].vis[i] = rnd() & 1;
        t[k].dfs2(1, 1);
    }
    while (q-- > 0) {
        static int op, x, y, z;
        cin >> op >> x >> y;
        if (op == 1) {
            val.modify(x, y);
            for (int k = 0; k < MAXV; k++)
                if (t[k].vis[x]) t[k].modify(x, y);
        } else {
            cin >> z;
            ans.clear();
            for (int i = 0; i < MAXV; i++) ans.insert(t[i].query(x, y));
            // cerr << val.query(lca(x, y)) << '\n';
            ans.insert(val.query(lca(x, y)));
            cout << ans.query(z) << '\n';
        }
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 1e5 + 10;
int n, q, w[MAXN], fa[MAXN];
vector<int> g[MAXN];

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

void dfs(int u) {
    for (auto v : g[u]) {
        if (v == fa[u]) continue;
        fa[v] = u;
        dfs(v);
    }
}

void modify(int u, int val) {
    w[u] ^= val;
    for (auto v : g[u]) {
        if (v == fa[u]) continue;
        modify(v, val);
    }
}

bitset<MAXN> vis;
int query(int u, int v, int val) {
    int tmp = v;
    vis.reset();
    ans.clear();
    while (tmp) vis[tmp] = 1, tmp = fa[tmp];
    while (!vis[u]) {
        ans.insert(w[u]);
        u = fa[u];
    }
    ans.insert(w[u]);
    while (v ^ u) {
        ans.insert(w[v]);
        v = fa[v];
    }
    return ans.query(val);
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
    dfs(1);
    while (q-- > 0) {
        static int op, x, y, z;
        cin >> op >> x >> y;
        if (op == 1) {
            modify(x, y);
        } else {
            cin >> z;
            cout << query(x, y, z) << '\n';
        }
    }

    return 0;
}
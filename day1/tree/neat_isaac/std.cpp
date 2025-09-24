#include <ctime>
#include <iostream>
const int N = 1e5 + 5;
int n, m, rt, a[N], hed[N], tal[N << 1], nxt[N << 1], cnte;
void de(int u, int v) { tal[++cnte] = v, nxt[cnte] = hed[u], hed[u] = cnte; }
int dfn[N], sz[N], idx, fa[N][18], dep[N];
double sdep;
void dfs(int x) {
    dfn[x] = ++idx, sz[x] = 1, sdep += dep[x];
    for (int i = 1; i < 18; i++) fa[x][i] = fa[fa[x][i - 1]][i - 1];
    for (int i = hed[x], v; i; i = nxt[i])
        if (!sz[v = tal[i]]) fa[v][0] = x, dep[v] = dep[x] + 1, dfs(v), sz[x] += sz[v];
}
#define mid (lb + rb >> 1)
int mx[N << 2];
void md(int x, int t, int k, int lb, int rb) {
    if (lb == rb) return mx[x] = k, void();
    t <= mid ? md(x << 1, t, k, lb, mid) : md(x << 1 | 1, t, k, mid + 1, rb);
    mx[x] = std::max(mx[x << 1], mx[x << 1 | 1]);
}
int qr(int x, int l, int r, int lb, int rb) {
    if (l > r) return 0;
    if (l <= lb && rb <= r) return mx[x];
    int ret = 0;
    if (l <= mid) ret = qr(x << 1, l, r, lb, mid);
    if (r > mid) ret = std::max(ret, qr(x << 1 | 1, l, r, mid + 1, rb));
    return ret;
}
#undef mid
bool checkin(int x) { return dfn[x] <= dfn[rt] && dfn[rt] < dfn[x] + sz[x]; }
signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    int c;
    std::cin >> c >> n;
    for (int i = 1; i <= n; i++) std::cin >> a[i];
    for (int i = 1, u, v; i < n; i++) std::cin >> u >> v, de(u, v), de(v, u);
    rt = 1, dfs(1);
    for (int i = 1; i <= n; i++) md(1, dfn[i], a[i], 1, n);
    std::cin >> m;
    for (int i = 1, op, x, y; i <= m; i++) {
        std::cin >> op >> x;
        if (op == 1) std::cin >> y, md(1, dfn[x], y, 1, n);
        if (op == 2) {
            if (!checkin(x))
                std::cout << qr(1, dfn[x], dfn[x] + sz[x] - 1, 1, n) << '\n';
            else {
                int t = rt;
                for (int j = 17; j >= 0; j--)
                    if (dep[fa[t][j]] > dep[x]) t = fa[t][j];
                std::cout << std::max(qr(1, 1, dfn[t] - 1, 1, n), qr(1, dfn[t] + sz[t], n, 1, n)) << '\n';
            }
        }
        if (op == 3) rt = x;
    }
    std::cerr << 1000.0 * clock() / CLOCKS_PER_SEC << ' ' << sdep / n;
}
#include <iostream>
#define int long long
const int N = 1e5 + 5;
int n, m, rt, a[N], b[N], hed[N], tal[N << 1], nxt[N << 1], cnte;
void de(int u, int v) { tal[++cnte] = v, nxt[cnte] = hed[u], hed[u] = cnte; }
int dfn[N], sz[N], idx, fa[N][18], dep[N];
void dfs(int x) {
    b[dfn[x] = ++idx] = a[x], sz[x] = 1;
    for (int i = 1; i < 18; i++) fa[x][i] = fa[fa[x][i - 1]][i - 1];
    for (int i = hed[x], v; i; i = nxt[i])
        if (!sz[v = tal[i]]) fa[v][0] = x, dep[v] = dep[x] + 1, dfs(v), sz[x] += sz[v];
}
int sum[N], mx[18][N];
void init() {
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + b[i], mx[0][i] = b[i];
    for (int i = 1; 1 << i <= n; i++)
        for (int j = 1; j + (1 << i) - 1 <= n; j++) mx[i][j] = std::max(mx[i - 1][j], mx[i - 1][j + (1 << i - 1)]);
}
bool checkin(int x) { return dfn[x] <= dfn[rt] && dfn[rt] < dfn[x] + sz[x]; }
int qsum(int l, int r) { return sum[r] - sum[l - 1]; }
int qmx(int l, int r) {
    int d = 31 - __builtin_clz(r - l + 1);
    return std::max(mx[d][l], mx[d][r - (1 << d) + 1]);
}
int jmp(int x, int y) {
    for (int i = 17; i >= 0; i--)
        if (dep[fa[x][i]] > dep[y]) x = fa[x][i];
    return x;
}
signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    int c;
    std::cin >> c >> n;
    for (int i = 1; i <= n; i++) std::cin >> a[i];
    for (int i = 1, u, v; i < n; i++) std::cin >> u >> v, de(u, v), de(v, u);
    dfs(rt = 1), init();
    std::cin >> m;
    for (int i = 1, op, x; i <= m; i++) {
        std::cin >> op >> x;
        if (op == 1) {
            if (!checkin(x))
                std::cout << qmx(dfn[x], dfn[x] + sz[x] - 1) << '\n';
            else {
                int t = jmp(rt, x);
                std::cout << std::max(qmx(1, dfn[t] - 1), qmx(dfn[t] + sz[t], n)) << '\n';
            }
        }
        if (op == 2) {
            if (!checkin(x))
                std::cout << qsum(dfn[x], dfn[x] + sz[x] - 1) << '\n';
            else {
                int t = jmp(rt, x);
                std::cout << qsum(1, dfn[t] - 1) + qsum(dfn[t] + sz[t], n) << '\n';
            }
        }
        if (op == 3) rt = x;
    }
}
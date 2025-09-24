#include <bits/stdc++.h>
#define int long long

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 2e5 + 10, mod = 998244353;
int N, M, n, k, sum, p[MAXN], q[MAXN], frac[MAXN];

int qpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) (res *= a) %= mod;
        if (b >>= 1) (a *= a) %= mod;
    }
    return res;
}

int inv(int a) { return qpow(a, mod - 2); }

int C(int n, int m) { return frac[n] * inv(frac[m]) % mod * inv(frac[n - m]) % mod; }

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M >> k;
    int sumq = 0;
    n = N + M;
    frac[0] = 1;
    for (int i = 1; i <= n; i++) frac[i] = frac[i - 1] * i % mod;

    int tmp = C(n - 1, k - 1);
    for (int i = 1; i <= N; i++) cin >> p[i], q[i] = p[i] * tmp % mod, (sumq += q[i]) %= mod;
    for (int i = N + 1; i <= N + M; i++)
        cin >> p[i], q[i] = p[i] * tmp % mod, (sum += q[i]) %= mod, (sumq += q[i]) %= mod;
    assert(sumq == 1);

    int t = (k - 1) * inv(n - 1) % mod;
    int E = M * t % mod + sum * (n - k) % mod * inv(n - 1) % mod;

    int ans = (E - E * E % mod) % mod;
    (ans += (2 * t % mod * (M - 1) % mod * sum % mod)) %= mod;
    (ans += (k - 1) * (k - 2) % mod * inv((n - 1) * (n - 2) % mod) % mod *
            (M * (M - 1) % mod - 2 * (M - 1) * sum % mod) % mod) %= mod;
    cout << (E + mod) % mod << '\n';
    cout << (ans + mod) % mod << '\n';

    return 0;
}
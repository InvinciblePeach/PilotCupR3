#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;

long long modpow(long long a, long long e) {
    long long r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;
    int n = N + M;

    vector<long long> p(n);
    long long sump = 0;
    for (int i = 0; i < N; i++) {
        cin >> p[i];
        sump = (sump + p[i]) % MOD;
    }
    for (int i = 0; i < M; i++) {
        cin >> p[N + i];
        sump = (sump + p[N + i]) % MOD;
    }

    long long inv_sump = modpow(sump, MOD - 2);

    // compute w
    long long w = 0;
    for (int i = N; i < n; i++) {
        w = (w + p[i] * inv_sump) % MOD;
    }

    long long inv_n1 = modpow(n - 1, MOD - 2);
    long long inv_n2 = modpow(1LL * (n - 1) * (n - 2) % MOD, MOD - 2);
    long long A = (1LL * (K - 1) * inv_n1) % MOD;
    long long D = (1LL * (K - 1) * (K - 2) % MOD) * inv_n2 % MOD;

    long long one_minus_A = (1 - A + MOD) % MOD;
    long long E = ((1LL * M * A) % MOD + one_minus_A * w % MOD) % MOD;

    long long inv2 = (MOD + 1) / 2; // =2^{-1} mod MOD
    long long term1 = D * (1LL * M * (M - 1) % MOD * inv2 % MOD) % MOD;
    long long term2 = ((A - D + MOD) % MOD) * ((long long)(M - 1) * w % MOD) % MOD;

    long long var = ((E - E * E % MOD + MOD) % MOD + (2 * (term1 + term2) % MOD)) % MOD;

    cout << E << "\n" << var << "\n";
    return 0;
}

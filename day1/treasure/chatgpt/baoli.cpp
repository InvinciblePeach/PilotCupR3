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

long long C(int n, int k) {
    if (k < 0 || k > n) return 0;
    long long r = 1;
    for (int i = 1; i <= k; i++) {
        r = r * (n - i + 1) % MOD * modpow(i, MOD - 2) % MOD;
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

    long long Z = C(n - 1, K - 1) * sump % MOD;
    long long invZ = modpow(Z, MOD - 2);

    // 枚举所有大小为K的组合
    vector<int> sel(n);
    fill(sel.begin(), sel.begin() + K, 1);

    long long E = 0, E2 = 0;

    long long sum = 0;
    do {
        long long sumw = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (sel[i]) {
                sumw = (sumw + p[i]) % MOD;
                if (i >= N) cnt++;
            }
        long long prob = sumw * invZ % MOD;
        sum = (sum + sumw) % MOD;
        E = (E + prob * cnt) % MOD;
        E2 = (E2 + prob * (1LL * cnt * cnt % MOD)) % MOD;
    } while (prev_permutation(sel.begin(), sel.end()));
    assert(sum == 1);

    long long var = (E2 - E * E % MOD + MOD) % MOD;

    cout << E << "\n" << var << "\n";

    return 0;
}

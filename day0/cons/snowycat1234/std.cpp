#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("construction.in", "r", stdin);
    // freopen("construction.out", "w", stdout);
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int n, T;
    cin >> T;
    while (T--) {
        cin >> n;
        if (n == 0) {
            cout << "0 0 0 0\n";
            return 0;
        }
        if (n & 1) {
            cout << (n + 1) / 2 << ' ' << (n + 1) / 2 << ' ' << (n - 1) / 2 << ' ' << (n - 1) / 2 << '\n';
        } else if (n % 4) {
            cout << n << ' ' << n << ' ' << n << ' ' << n - 1 << '\n';
        } else {
            cout << (n / 4 + 1) << ' ' << (n / 4 + 1) << ' ' << (n / 4 - 1) << ' ' << (n / 4 - 1) << '\n';
        }
    }
}
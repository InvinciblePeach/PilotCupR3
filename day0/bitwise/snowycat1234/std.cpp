#include <bits/stdc++.h>
using namespace std;
#define MAXN 10000500
#define int long long
struct ln {
    int a, b, c;
} arr[MAXN];
struct pt {
    int x, y, res, id;
} que[MAXN];
int cnt;

int n, m, a[MAXN];

signed main() {
    // freopen("bitwise.in", "r", stdin);
    // freopen("bitwise.out", "w", stdout);
    double nw = clock();
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n - 2; i++) {
        int sa = a[i] & a[i + 1], sb = a[i] | a[i + 1];
        int c = a[i] ^ a[i + 1];
        int ub = 1ll << (__lg(a[i]) + 2);
        int sum = a[i + 1];
        for (int j = i + 2; j <= n && sum <= ub; j++) {
            sa += a[j] & a[j - 1];
            sb += a[j] | a[j - 1];
            c ^= a[j];
            if (a[i] >= a[j]) {
                // cout << sa << ' ' << sb << ' '<< c << ' ' << (a[i]^a[j])+(a[i]&a[j])+(a[i]|a[j]) << '\n';
                arr[++cnt] = {sa, sb, c + (a[i] ^ a[j]) + (a[i] & a[j]) + (a[i] | a[j])};
            }
            sum += a[j];
        }
    }
    reverse(a + 1, a + n + 1);
    for (int i = 1; i <= n - 2; i++) {
        int sa = a[i] & a[i + 1], sb = a[i] | a[i + 1];
        int c = a[i] ^ a[i + 1];
        int ub = 1ll << (__lg(a[i]) + 2);
        int sum = a[i + 1];
        for (int j = i + 2; j <= n && sum <= ub; j++) {
            sa += a[j] & a[j - 1];
            sb += a[j] | a[j - 1];
            c ^= a[j];
            if (a[i] > a[j]) {
                arr[++cnt] = {sa, sb, c + (a[i] ^ a[j]) + (a[i] & a[j]) + (a[i] | a[j])};
            }
            sum += a[j];
        }
    }
    for (int i = 1; i <= m; i++) {
        cin >> que[i].x >> que[i].y;
        que[i].id = i;
    }
    sort(que + 1, que + m + 1, [](const pt x, const pt y) {
        if (x.x ^ y.x) return x.x < y.x;
        return x.y < y.y;
    });
    for (int i = 1; i <= cnt; i++) {
        int l = 1, r = m;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if ((__int128)arr[i].a * que[mid].x + (__int128)arr[i].b * que[mid].y < arr[i].c) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        que[l].res++;
        l = 1, r = m;
        while (l <= r) {
            int mid = (l + r) >> 1;
            // cerr << arr[i].a << ' '<< arr[i].b << ' ' << arr[i].c << ' ' << que[mid].x << ' ' << que[mid].y << '\n';
            if (arr[i].a * que[mid].x + arr[i].b * que[mid].y <= arr[i].c) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        // cout << l << ' ' << r << '\n';
        que[l].res--;
    }
    for (int i = 2; i <= m; i++) {
        que[i].res += que[i - 1].res;
    }
    sort(que + 1, que + m + 1, [](const pt x, const pt y) { return x.id < y.id; });
    for (int i = 1; i <= m; i++) {
        cout << que[i].res << '\n';
    }
    cerr << (clock() - nw) / CLOCKS_PER_SEC << "s\n";
}
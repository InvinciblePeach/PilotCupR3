#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

signed main() {
    system("g++ std.cpp -O2 -o std");
    system("g++ baoli.cpp -O2 -o baoli");
    for (int _ = 1; _ <= 1000; _++) {
        cout << "===========" << _ << '\n';
        system("python gen.py > data.in");
        system("./std < data.in > std.out");
        system("./baoli < data.in > tmp.out");
        if (system("diff tmp.out std.out -Z")) return cout << "WA\n", 0;
        cout << "AC\n";
    }

    return 0;
}
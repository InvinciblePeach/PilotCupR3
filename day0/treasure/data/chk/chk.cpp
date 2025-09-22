#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int ans1, ans2, ouf1, ouf2;

signed main(int argc, char *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    registerLemonChecker(argc, argv);
    ans1 = ans.readInt(), ans2 = ans.readInt();
    ouf1 = ouf.readInt(), ouf2 = ouf.readInt();
    if (ans1 == ouf1 && ans2 == ouf2)
        quitf(_ok, "Well done");
    else if (ans1 == ouf1)
        quitp(0.3, "Only accept line 1");
    else
        quitf(_wa, "grade like this, how can noip");
    return 0;
}
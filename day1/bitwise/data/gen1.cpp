#include<bits/stdc++.h>
using namespace std;
#define int long long
mt19937_64 rnd(std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()).time_since_epoch().count());
int gen(int x){
    if(!x)return 0;
    return rnd() % x + 1;
}
int Va = 10,Vq = 100;
#define MAXN 100500
int n = 100000,m = 100000;
int x[MAXN],y[MAXN];
pair<int,int> pr[MAXN];
signed main(){
    n -= gen(5),m -= gen(5);
    cout << n << ' ' << m << '\n';
    for(int i = 1;i <= n;i ++){
        int k = abs((i / 4) % (Va) * 2-Va);
        // cout << k << ' ';
        cout << ((1 << k) + gen((1 << k)-1)) << ' ';
        // cout << (i & 1) + 1 << ' ';
    }
    cout << '\n';
    for(int i = 1;i <= m;i ++){
        if(i&1)x[i] = gen(Vq),y[i] = gen(Vq);
        else x[i] = gen(10),y[i] = gen(10);
    }
    sort(x + 1,x + m + 1);
    sort(y + 1,y + m + 1);
    for(int i = 1;i <= m;i ++){
        pr[i].first = x[i],pr[i].second = y[i];
    }
    shuffle(pr + 1,pr + m + 1,rnd);
    for(int i = 1;i <= m;i ++){
        cout << pr[i].first << ' ' << pr[i].second << '\n';
    }
}
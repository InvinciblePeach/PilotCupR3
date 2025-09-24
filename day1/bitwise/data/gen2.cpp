#include<bits/stdc++.h>
using namespace std;
#define int long long
mt19937_64 rnd(std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()).time_since_epoch().count());
int gen(int x){
    if(!x)return 0;
    return rnd() % x + 1;
}
int Va = 50,Vq = 100;
#define MAXN 300500
int n = 100000,m = 100000;
int x[MAXN],y[MAXN],a[MAXN],cnt,pcnt;
pair<int,int> pr[MAXN<<5],f[MAXN];
vector<pair<int,int> > cand;
map<pair<int,int> ,int> mp;
struct ln{
    int a,b,c;
}arr[MAXN<<5];

void exgcd(int a,int b,int &g,int &x,int &y)
{
	if(b==0){x=1;y=0;g=a;return;}
	exgcd(b,a%b,g,x,y);
    int z = x; x = y; y = z - (a/b)*y;
}
int gcd(int x,int y){
    if(!y)return x;
    return gcd(y,x%y);
}
int _cnt = 0;
void solve(){
    for(int i = 1;i <= n - 2;i ++){
        int sa = a[i] & a[i + 1],sb = a[i] | a[i + 1];
        int c = a[i] ^ a[i + 1];
        int ub = 1ll << (__lg(a[i]) + 2);
        int sum = a[i + 1];
        for(int j = i + 2;j <= n && sum <= ub;j ++){
            sa += a[j] & a[j - 1];
            sb += a[j] | a[j - 1];
            c ^= a[j];
            if(a[i] >= a[j]){
                // cout << sa << ' ' << sb << ' '<< c << ' ' << (a[i]^a[j])+(a[i]&a[j])+(a[i]|a[j]) << '\n';
                arr[++cnt] = {sa,sb,c+(a[i]^a[j])+(a[i]&a[j])+(a[i]|a[j])};
            }
            sum += a[j];
        }
    }
    reverse(a + 1,a + n + 1);
    for(int i = 1;i <= n - 2;i ++){
        int sa = a[i] & a[i + 1],sb = a[i] | a[i + 1];
        int c = a[i] ^ a[i + 1];
        int ub = 1ll << (__lg(a[i]) + 2);
        int sum = a[i + 1];
        for(int j = i + 2;j <= n && sum <= ub;j ++){
            sa += a[j] & a[j - 1];
            sb += a[j] | a[j - 1];
            c ^= a[j];
            if(a[i] > a[j]){
                arr[++cnt] = {sa,sb,c+(a[i]^a[j])+(a[i]&a[j])+(a[i]|a[j])};
            }
            sum += a[j];
        }
    }
    // while(1){
        
    //     int g,x,y,a = 1,b = 1,c = 2;
    //     exgcd(a,b,g,x,y);
    //     if(c % g)break;
    //     int dx = b / gcd(a,b);
    //     int dy = a / gcd(a,b);
    //     x*=c/g;
    //     y*=c/g;
    //     // dx*=c/g;
    //     // dy*=c/g;
    //     int pre = ceil(-1.0*x/dx);
    //     x+=pre*dx,y-=pre*dy;
    //     if(!x)x += dx,y -= dy;
    //     cerr << x << ' ' << y <<' ' << dx << ' ' << dy << '\n';
    //     while(y>0){
    //         assert(x && y);
    //         mp[{x,y}]++;
    //         x+=dx,y-=dy;
    //     }
    //     break;
    // }
    cerr << cnt << '\n';
    for(int i  =1;i <= cnt;i ++){
        // if(i % 1000==0)cerr << i << '\n';
        // cerr<<arr[i].a<<' ' <<arr[i].b<< ' ' <<arr[i].c << '\n';
        if(!arr[i].a){
            if(arr[i].c % arr[i].b)continue;
            for(int j = 1;j <= 100;j ++)mp[{j,arr[i].c/arr[i].b}]++;
            continue;
        }
        // _cnt += (2*arr[i].a + arr[i].b == arr[i].c);
        int g,x,y,a = arr[i].a,b = arr[i].b,c = arr[i].c;
        exgcd(a,b,g,x,y);
        if(c % g)continue;
        int dx = b / gcd(a,b);
        int dy = a / gcd(a,b);
        x*=c/g;
        y*=c/g;
        // dx*=c/g;
        // dy*=c/g;
        int pre = ceil(-1.0*x/dx);
        x+=pre*dx,y-=pre*dy;
        if(!x)x += dx,y -= dy;
        assert(dx&&dy);
        // cerr << x << ' ' << y <<' ' << dx << ' ' << dy << '\n';
        while(y>0){
            assert(x && y);
            mp[{x,y}]++;
            // cerr <<x << ' ' << y << '\n';
            x+=dx,y-=dy;
        }
    }
    // cerr << _cnt << '\n';
}
#define pii pair<int,int>
struct BIT{
    pii arr[MAXN];
    int lbit(int x){
        return x & -x;
    }
    void m_add(int pos,pii d){
        for(;pos < MAXN;pos += lbit(pos))arr[pos] = max(d,arr[pos]);
    }
    pii q_sum(int pos){
        pii res = {0,0};
        for(;pos;pos -= lbit(pos))res = max(arr[pos],res);
        return res;
    }
}bit;;
signed main(){
    n -= gen(5),m -= gen(5);
    cout << n << ' ' << m << '\n';
    for(int i = 1;i <= n;i ++){
        // int k = abs((i / 4) % (Va) * 2-Va);
        // cout << (a[i]=(1 << k) + gen((1 << k)-1)) << ' ';
        cout << (a[i] = gen(Va)) << ' ';
    }
    cout << '\n';
    cerr << "========\n";
    solve();
    for(auto p : mp){
        assert(p.first.first&&p.first.second);
        pr[++pcnt] = p.first;
    }
    cerr << "========\n";
    sort(pr+1,pr+pcnt+1);
    pii mx = {0,0};
    cerr << "========\n";
    cerr << pcnt << '\n';
    for(int i = 1;i <= pcnt;i ++){
        pii p = bit.q_sum(pr[i].second);
        f[i] = max((pii){1ll,0ll},(pii){p.first+1,p.second});
        bit.m_add(pr[i].second,{f[i].first,i});
        mx = max(mx,{f[i].first,i});
        // cerr <<pr[i].first << ' ' << pr[i].second << ' '<< f[i].first << '-' << f[i].second << '\n';
    }
    cerr << "========\n";
    int u = mx.second;
    while(u){
        cand.push_back(pr[u]);
        u = f[u].second;
        // cerr << u << '\n';
    }
    // cerr << "========\n";
    for(int i = 1;i <= m;i ++){
        cout << cand[i%cand.size()].first << ' ' << cand[i%cand.size()].second << '\n';
    }
}
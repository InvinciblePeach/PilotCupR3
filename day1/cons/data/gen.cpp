#include<bits/stdc++.h>
using namespace std;
#define int long long
mt19937_64 rnd(std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()).time_since_epoch().count());
int gen(int x){
    return rnd() % x + 1;
}
int V = 20;
signed main(){
    int op = rnd() % 3;
    if(op == 0){
        cout << 2 * gen(V / 2 - 1) + 1 << '\n';
    }else if(op == 1){
        cout << 2*(2 * gen(V / 4 - 2) + 1) << '\n';
    }else{
        cout << 4 * gen(V / 4) << '\n';
    }
}  
#include "testlib.h"
using namespace std;
int main(int argc,char* argv[]) {
	registerLemonChecker(argc,argv);
	int T = inf.readInt(),n;
	while(T --){
		n = inf.readInt();
		int p = ouf.readInt(0,n,"p"),q = ouf.readInt(0,n,"q"),s = ouf.readInt(0,n,"s"),t = ouf.readInt(0,n,"t");
		if((1ll * p * q - 1ll * s * t) != n){
			quit(_wa,"p*q-s*t does NOT equal to n.");
		}
		int ans;
		if(n & 1)ans = 0;
		else if(n % 4)ans = 1;
		else ans = 0;
		if(abs(p - q) + abs(s - t) != ans){
			quit(_wa,"Your plan is not the best.");
		}
	}
	quit(_ok,"good job");
	return 0;
}

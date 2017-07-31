#include <bits/stdc++.h>
using namespace std;

void build_KMP(int n, char *s, int *f){ // 1 base
	f[0]=-1, f[1]=0;
	for (int i=2; i<=n; i++){
		int w = f[i-1];
		while (w>=0 && s[w+1]!=s[i])w = f[w];
		f[i]=w+1;
	}
}

int gcd(int a, int b){
    if (b==0)return a;
    return gcd(b,a%b);
}
long long lcm(int a, int b){
    return (long long)a/gcd(a,b)*b;
}

const int MAXN = 100005;

int n, m;
char sa[MAXN], sb[MAXN];
int fa[MAXN], fb[MAXN];
int ca, cb, d;

int solve(){
    if ((long long)gcd(n,m)%lcm(ca,cb))return 0;
    int d = (int) lcm(ca,cb);
    
    int w=0;
    for (int i=1; i<=d; i++){
        while (w>=0 && sb[w+1]!=sa[i])w = fb[w];
        if (++w==d)return d;
    }
    for (int i=1; i<=d; i++){
        while (w>=0 && sb[w+1]!=sa[i])w = fb[w];
        if (++w==d)return d;
    }
    return 0;
}

int main(){
    int T; cin >> T;

    while (T--){
        scanf("%s", sa+1);
        build_KMP(n=strlen(sa+1), sa, fa);
        ca = n-fa[n];

        scanf("%s", sb+1);
        build_KMP(m=strlen(sb+1), sb, fb);
        cb = m-fb[m];

        cout << solve() << endl;
    }
}

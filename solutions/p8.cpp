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

const int MAXN = 100005;

int max_length(int n, char *a, int m, char *b){
    static int f[MAXN];
    build_KMP(m,b,f);

    int ans=0;
    for (int i=1, w=0; i<=n; i++){
        while ( w>=0 && b[w+1]!=a[i] )w=f[w];
		w++;
        ans = max(ans,w);
		if (w==m)w=f[w];
    }
    return ans;
}

bool check(char *a, char *b){
    int n = strlen(a+1) , m = strlen(b+1);

    int la=max_length(n,a,m,b);
    reverse(a+1,a+1+n);
    reverse(b+1,b+1+m);
    int lb=max_length(n,a,m,b);
    return la+lb>=m;
}

char a[MAXN], b[MAXN];

int main(){
    int T; cin >> T;

    while (T-- && scanf("%s%s", a+1, b+1)){
        bool ab=check(a,b), ba=check(b,a);
        if ((ab^ba)==0)puts("same");
        else puts(ab?"Sam":"Lancy");
    }
}

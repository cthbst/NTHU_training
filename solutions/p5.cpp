#include <bits/stdc++.h>
using namespace std;

template<typename T>
void build_z(int n, T *a, int *z){ // 0 base
    int L=0, R=0;
    z[0]=1;
    for (int i=1; i<n; i++){
        z[i] = (R>i) ? min(z[2*L-i], R-i) : 1;
        while (i-z[i]>=0 && i+z[i]<n && a[i-z[i]] == a[i+z[i]])z[i]++;
        if (i+z[i] > R) L = i, R = i+z[i];
    }
}

const int MAXN = 1003;

template<typename T>
void sym(int n, T a[MAXN][MAXN]){
    for (int i=1; i<=n; i++)
    for (int j=i+1; j<=n; j++)
        swap(a[i][j],a[j][i]);
}

int n;
char a[MAXN][MAXN];
int z[2][MAXN][MAXN];
int dp[4][MAXN][MAXN];

void build(){
    for (int i=1; i<=n; i++)
        build_z(n, a[i]+1, z[0][i]+1);
    sym(n,a);
    for (int i=1; i<=n; i++)
        build_z(n, a[i]+1, z[1][i]+1);
    sym(n,z[1]);

    memset(dp,0,sizeof(dp));
    for (int i=1; i<=n ;i++){
        for (int j=1; j<=n; j++){
            dp[0][i][j] = min(dp[0][i-1][j]+1,z[0][i][j]);
            dp[1][i][j] = min(dp[1][i][j-1]+1,z[1][i][j]);
        }
    }
    for (int i=n; i>=1; i--){
        for (int j=n; j>=1; j--){
            dp[2][i][j] = min(dp[2][i+1][j]+1,z[0][i][j]);
            dp[3][i][j] = min(dp[3][i][j+1]+1,z[1][i][j]);
        }
    }
}

int main(){
    int T; cin >> T;
    while (T--){
        scanf("%d", &n);
        for (int i=1; i<=n; i++)scanf("%s",a[i]+1);
        build();
        int mxd=0;
        for (int i=1; i<=n ;i++){
            for (int j=1; j<=n; j++){
                int d = min( dp[0][i][j],
                        min( dp[1][i][j],
                        min( dp[2][i][j],
                             dp[3][i][j])));
                mxd = max(mxd,d);
            }
        }
        cout << mxd*(mxd-1)*2+1 << endl;
    }
}

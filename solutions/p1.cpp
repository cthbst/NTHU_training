#include <bits/stdc++.h>
using namespace std;

const int MAXP = 20004;
bitset<MAXP> p;
void build_prime(){
    p.set();
    p[0]=p[1]=0;
    for (int i=2; i<MAXP; i++)if (p[i]){
        for (int j=i+i; j<MAXP; j+=i)p[j]=0;
    }
}

const int MAXN = 1003;
int n, a[MAXN], b[MAXN], c[MAXN];
bool vis[MAXN];
queue<int> que;

void input(){
    cin >> n;
    for (int i=1, id; i<=n; i++){
        cin >> id;
        a[i] = id % 10000;
        b[i] = id / 10000;
    }
}

void solve(){
    int ans=0;
    memset(vis,0,sizeof(vis));
    for (int i=1; i<=n; i++)if (!vis[i]){
        int cnt[2]={0,0};
        vis[i]=1, c[i]=0;
        que.push(i);
        while (que.size()){
            int u = que.front(); que.pop();
            cnt[ b[u]^c[u] ]++;
            for (int v=1; v<=n; v++)if (!vis[v]){
                if (!p[ a[u]+a[v] ])continue;
                vis[v]=1, c[v] = c[u]^1;
                que.push(v);
            }
        }
        ans += min(cnt[0],cnt[1]);
    }
    cout << ans << endl;
}

int main(){
    build_prime();

    int T; cin >>T;

    while (T--){
        input();
        solve();
    }
}

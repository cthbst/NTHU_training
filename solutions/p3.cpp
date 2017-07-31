#include <bits/stdc++.h>
using namespace std;

typedef struct Edge{
    int v; long long len;
    bool operator > (const Edge &b)const { return len>b.len; }
} State;

const long long INF = 1LL<<60;

void Dijkstra(int n, vector<Edge> G[], long long d[], int s, int t=-1){
    static priority_queue<State, vector<State>, greater<State> > pq;
    while ( pq.size() )pq.pop();
    for (int i=1; i<=n; i++)d[i]=INF;
    d[s]=0; pq.push( (State){s,d[s]} );
    while ( pq.size() ){
        auto x = pq.top(); pq.pop();
        int u = x.v;
        if (d[u]<x.len)continue;
        if (u==t)return;
        for (auto &e:G[u]){
            if (d[e.v] > d[u]+e.len){
                d[e.v] = d[u]+e.len;
                pq.push( (State) {e.v,d[e.v]} );
            }
        }
    }
}

const int MAXN = 100005;

int n, m;
vector<Edge> G[MAXN];
long long d[MAXN];
int deg[MAXN], dp[MAXN];
queue<int> que;

void init(){
    for (int i=0; i<MAXN; i++)G[i].clear();
    memset(deg,0,sizeof(deg));
    memset(dp,-1,sizeof(dp));
}

int main(){
    int T; cin >> T;

    while (T--){
        init();
        cin >> n >> m;
        for (int i=0, u, v, w; i<m; i++){
            scanf("%d %d %d", &u, &v, &w);
            G[u].push_back( (Edge){v,(long long)w} );
            G[v].push_back( (Edge){u,(long long)w} );
        }


        Dijkstra(n,G,d,1);
        for (int u=1; u<=n; u++){
            for (auto e:G[u]){
                if (d[u]+e.len==d[e.v])deg[e.v]++;
            }
        }

        dp[1]=1;
        que.push(1);
        while (que.size()){
            int u = que.front(); que.pop();
            for (auto e:G[u]){
                if (d[u]+e.len!=d[e.v])continue;
                dp[e.v] = max(dp[e.v],dp[u]+1);
                deg[e.v]--;
                if (deg[e.v]==0)que.push(e.v);
            }
        }

        for (int i=1; i<=n; i++)printf("%d\n", dp[i]);
    }
}

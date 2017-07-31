#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int u, v, w;
    bool operator < (const Edge &b)const{ return w<b.w; }
};

const int MAXN = 30004;

int n, m;
Edge edges[MAXN];
int root[MAXN], par[MAXN], dis[MAXN], sz[MAXN];

int find(int x){
    if (root[x]==x)return x;
    return root[x]=find(root[x]);
}

int main(){
    cin >> n >> m;
    
    for (int i=1; i<=n; i++){
        root[i] = par[i] = i;
        dis[i] = -1;
        sz[i]=1;
    }

    for (int i=0, u, v, w; i<m; i++){
        scanf("%d %d %d", &u, &v, &w);
        edges[i] = (Edge){u,v,w};
    }
    sort(edges,edges+m);
    for (int i=0; i<m; i++){
        int u = find(edges[i].u);
        int v = find(edges[i].v);
        int w = edges[i].w;
        if (u==v)continue;

        if (sz[u]<sz[v])swap(u,v);
        root[v] = par[v] = u;
        dis[v] = w;
        sz[u] += sz[v];
    }

    int Q, u, v; cin >> Q;
    while (Q-- && scanf("%d %d", &u, &v)){
        if (find(u)!=find(v)){
            puts("536870912");
        }
        else {
            int ans=0;
            while (u!=v){
                if (sz[u]<sz[v])swap(u,v);
                ans = max(ans,dis[v]);
                v = par[v];
            }
            printf("%d\n", ans);
        }
    }
}

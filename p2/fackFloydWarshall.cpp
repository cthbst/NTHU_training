#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3003;
const long long INF = 1LL<<62;

int n, m;
long long d[MAXN][MAXN];

int main(){
	cin >> n >> m;
	
	// init	
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			d[i][j] = INF;
		}
		d[i][i] = 0;
	}
	
	// input
	for (int i=1, u, v, w; i<=m; i++){
		cin >> u >> v >> w;
		d[v][u] = d[u][v] = min(d[u][v],w);
	}
	
	// Floyd-Warshall
	for (int k=1; k<=n; k++){
		for (int i=1; i<=n; i++){
			for (int j=1; j<=n; j++){
				d[i][j] = min(d[i][j], max(d[i][k],d[k][j]) )
			}
		}
	}
	
	// Query
	int Q; cin >> Q;
	while (Q-->0){
		int u, v;
		cin >> u >> v;
		cout << d[u][v] << endl;
	}
}

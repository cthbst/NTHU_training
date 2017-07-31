#include <bits/stdc++.h>
using namespace std;

struct Suffix_Automaton{
	struct State{
		int par, val, dp;
		int go[10];
		State (int _val=0):par(0),val(_val){
            dp=0;
			memset(go,0,40);
		}
	};
	vector<State> vec;
	int root;

	void init();
	void add(const string& s);
	void extend(int p,const int &w);
};

void Suffix_Automaton::init(){
	vec.resize(2);
	vec[0] = vec[1] = State(0);
	root = 1;
}

void Suffix_Automaton::add(const string& s){
	int w = root, i=0;

	for (; i<s.size(); i++){
		int c = s[i]-'0';
		if (vec[w].go[c]==0)break;	
		if (vec[ vec[w].go[c] ].val != i+1)break;

		w = vec[w].go[c];
	}

	for (; i<s.size(); i++){
		int c = s[i]-'0';
		extend(w,c);
		w = vec[w].go[c];
	}
}

void Suffix_Automaton::extend(int p,const int &w){
	int np = vec.size();
	vec.push_back( State(vec[p].val+1) );
	for (; p && vec[p].go[w]==0; p=vec[p].par)
		vec[p].go[w] = np;
	if (p==0){
		vec[np].par = root;
	}
	else if (vec[ vec[p].go[w] ].val == vec[p].val+1){
		vec[np].par = vec[p].go[w];
	}
	else {
		int q = vec[p].go[w], r = vec.size();
		vec.push_back(vec[q]);
		vec[r].val = vec[p].val+1;
		vec[q].par = vec[np].par = r;
		for (; p && vec[p].go[w] == q; p=vec[p].par)
			vec[p].go[w] = r;
	}
}

Suffix_Automaton SAM;
int n;
string s;
queue<int> que;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T; cin >>T; 

    while (T--){
        SAM.init();
        cin >> n;
        for (int i=0; i<n; i++){
            cin >> s;
            SAM.add(s);
        }
        
        long long ans = 0;
        SAM.vec[1].dp=1;
        que.push(1);

        while (que.size()){
            auto &u = SAM.vec[que.front()]; que.pop();
            ans += (long long)u.dp;

            for (int i=0; i<10; i++)if (u.go[i]!=0){
                SAM.vec[ u.go[i] ].dp += u.dp;
                if (SAM.vec[ u.go[i] ].val == u.val+1){
                    que.push(u.go[i]);
                }
            }
        }

        cout << ans << endl;
    }
}

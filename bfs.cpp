#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
using state = pair<int,int>;
vector<vector<int>> g;
vector<vector<int>> vis;
queue<state> q;
int n,m;
#define f first
#define s second

int dx[] = {0,1,-1,0};
int dy[] = {-1,0,0,1};
bool isvalid(int x, int y){
	if(x>=0 and y>=0 and x<n and y<m and g[x][y]!=1){
		return 1;
	}
	return 0;
}
vector<state> neighbour(state node){
	vector<state> neighs;
	for(int k=0;k<4;k++){
		int x = node.f + dx[k];
		int y = node.s + dy[k];
		if(isvalid(x,y)){
			neighs.push_back({x,y});
		}
	}
	return neighs;
}

void bfs(state node){
	int count = 0;
	q.push(node);
	vis[node.f][node.s] = 1;
	while(!q.empty()){
		state v = q.front();
		count++;
		q.pop();
		for(state a: neighbour(node)){
			if(!vis[a.f][a.s]){
				vis[a.f][a.s] = ;
			}
		}
	}
}

void solve(){
    // Your code here

	cin>>n>>m;
	g.resize(n);
	state st, en;
    for(int i=0;i<n;i++){
    	g[i].resize(m);
    	for(int j=0;j<m;i++){
    		cin>>g[i][j];

    	}
    }


    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		if(g[i][j]==0){
    		
    			st = make_pair(i,j);
    			bfs(st);
    		}
    	}
    }
     
   






}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
            freopen("input.txt", "r", stdin);
            freopen("output.txt", "w", stdout);
    #endif
    int t; cin >> t; while(t--)
        
    solve();
    return 0;
}
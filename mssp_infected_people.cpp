/*

city represented as grid with n rows and m columns

cells having values 2 -> infected people
cells having values 1 -> normal people
cell having value 0 -> normal people

print the minimum time in which all people are infected, 

if not everyone can be infected, print -1.

smaple input 

3 3
0 1 2
0 1 2
1 1 2

sample output 

2




*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define F first
#define S second
vector<vector<int>> g;
using state = pair<int,int>;
queue<state> q;
vector<vector<int>> dis;
int n, m;
int dx[] = {0,-1,1,0};
int dy[] = {1, 0, 0, -1};

bool is_valid(int x, int y){
	if(x>=0 and x<n and y>=0 and y<m and g[x][y]!=0){
		return true;
	}
	return false;
}

void solve(){


	while(!q.empty()){
		int x = q.front().F, y = q.front().S;
		q.pop();
		for(int k=0;k<4;k++){
			int nx = x + dx[k], ny = y + dy[k];
			if(is_valid(nx, ny)){
				if(dis[nx][ny]>dis[x][y]+1){
					q.push({nx, ny});
					dis[nx][ny] = 1 + dis[x][y];
				}
			}
		}

	}
    // Your code here
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
     #ifndef ONLINE_JUDGE
            freopen("input.txt", "r", stdin);
            freopen("output.txt", "w", stdout);
     #endif
cin>>n>>m;
    // n=1000, m=1000;


    dis.assign(n, vector<int>(m, 1e9));
    g.resize(n);
    bool normal = false;
    for(int i=0;i<n;i++){
    	g[i].resize(m);
    	for(int j=0;j<m;j++){
    		cin>>g[i][j];
    		// g[i][j] = rand()%3;
    		if(g[i][j]==2) { q.push({i,j}); dis[i][j] = 0; }
    		else if(g[i][j]==1) normal = true;
    	}
    }
    if(q.empty() and normal){
    	cout<<-1<<endl; return 0;
    	    }

    if(q.empty()){
     	cout<<0<<endl; return 0;
     }


     // for(auto a: g) for(auto b: a) cout<<b<<" "; cout<<endl;
    // int t; cin >> t; while(t--)
    solve();
    
    int ans = 0;
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		if(g[i][j]==1){
    			ans = max(ans, dis[i][j]);
    		}
    	}
    }
    if(ans == 1e9 ) {cout<<-1<<endl;}
    else cout<<ans<<endl;
    return 0;
}
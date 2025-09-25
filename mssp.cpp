#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int n, m;
#define F first
#define S second
using state = pair<int,int>;

vector<vector<char>> g;
state st;
vector<state> mons; // store monster cells
vector<vector<int>> dis_pers; // store min distance from person
vector<vector<int>> dis_mons;
vector<vector<int>> vis; //store min distance from monsters
vector<state> bd_cells; //store boundary cells

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool is_valid(int x, int y){
	if(x>=0 and x<n and y>=0 and y<m and g[x][y]=='.'){
		return true;
	}
	return false;
}

void multi_bfs(){
	queue<state> q;
	for(auto it: mons){
		q.push(it);
		dis_mons[it.F][it.S] = 0;
	}
	while(!q.empty()){
		int x = q.front().F, y = q.front().S;
		
		q.pop();
		for(int k=0;k<4;k++){
			int nx = x + dx[k], ny = y + dy[k];
			if(is_valid(nx, ny)){
				  if(vis[nx][ny]==-1)
					{ q.push({nx, ny});}
			
					dis_mons[nx][ny] = min(dis_mons[nx][ny], dis_mons[x][y]+1);
				
			}
		}
	}
}

void bfs(state node){
	queue<state> q;
	q.push(node);
	dis_pers[node.F][node.S] = 0;
	while(!q.empty()){
		int x = q.front().F, y = q.front().S;
		vis[x][y]=1;
		q.pop();
		for(int k=0;k<4;k++){
			int nx = x+dx[k], ny = y+dy[k];
			if(is_valid(nx, ny)){
				if(vis[nx][ny]==-1){
					q.push({nx, ny});
				}
					
				
				dis_pers[nx][ny] = min(1+ dis_pers[x][y], dis_pers[nx][ny]);
			}
		}
		}
}



void solve(){
    // Your code here
	// multi source bfs to compute minimum distance of any monster to boundary
	vis.assign(n, vector<int>(m,-1));
    multi_bfs();

    // plain bfs to compute minimum distance of any boundary cell to person
    vis.assign(n, vector<int>(m,-1));
    bfs(st);
     //O(m+n)
    // check if distance of boundary cell from person is less than or equal to minimum ditance of any monster to boundary
    for(auto cell: bd_cells){
    	if(dis_pers[cell.F][cell.S]<dis_mons[cell.F][cell.S]){
    		cout<<"YES"<<endl;
    		cout<<dis_pers[cell.F][cell.S]<<endl;
    		return;
    	}
    }
    cout<<"NO"<<endl;

}

signed main(){
	#ifndef ONLINE_JUDGE
            freopen("input.txt", "r", stdin);
            freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // int t; cin >> t; while(t--)
    cin>>n>>m;
    g.resize(n);
    for(int i=0;i<n;i++){
    	g[i].resize(m);
    	for(int j=0;j<m;j++){
    		char ch;
    		cin>>ch;
    		g[i][j]=ch;
    		if(ch=='A'){
    			st = {i,j};
    			if(i==0||j==0||i==n-1||j==m-1){
    				bd_cells.push_back({i,j});
    			}
    		}
    		else if (ch=='M'){
    			mons.push_back({i,j});
    		}
    		else if((i==0||j==0||i==n-1||j==m-1) and ch == '.'){
    			bd_cells.push_back({i,j});
    		}
    	}
    }

    dis_pers.assign(n, vector<int>(m , 1e9));
    dis_mons.assign(n, vector<int>(m , 1e9));

    
    solve();
    return 0;
}
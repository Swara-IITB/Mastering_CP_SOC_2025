#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef map<ll,ll> mll;
typedef set<ll> sll;
#define ain(a,n) for(ll lambda=0; lambda<n; lambda++){cin >> a[lambda];}
#define aout(a,n) for(ll _=0; _<n; _++){cout << a[_] << ' ';}
#define F first
#define S second 
const ll N = 1000, INF = 1e18;
ll n,m, dx[]={1,0,-1,0}, dy[]={0,1,0,-1};
string dir = "DRUL";
vector<vector<ll>> mintime, mintimemy;
vector<string> grid;
vector<pair<ll,ll>> monsters;
pair<ll,ll> start,parent[N][N],endp;

bool in_bound(ll x, ll y){
    return x>=0 && x<n && y>=0  && y<m;
}
bool is_boundary(ll x, ll y){
    return x==0 || y==0 || x==n-1 || y==m-1;
}
void minmon(){
    mintime.assign(n,vector<ll>(m,INF));
    queue<pair<ll,ll>> q;
    for(auto u : monsters){
        ll u1= u.F, u2=u.S;
        mintime[u1][u2] = 0;
        q.push({u1,u2});
    }
        while(!q.empty()){
            pair<ll,ll> curr = q.front();q.pop();
            ll x = curr.F, y = curr.S;
            
            for(ll i=0; i<4; i++){
                ll nx = x + dx[i], ny=y+dy[i];
                if(in_bound(nx,ny) && grid[nx][ny] != '#' && mintime[nx][ny] > mintime[x][y]+1 ){
                    mintime[nx][ny] = mintime[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }
    
    return;
}

bool bfs(){
    mintimemy.assign(n,vector<ll>(m,INF));
    queue<pair<ll,ll>> q;
    q.push(start);
    mintimemy[start.F][start.S] = 0;
    while(!q.empty()){
        pair<ll,ll> curr = q.front(); q.pop();
        ll x = curr.F, y=curr.S;
        for(ll i=0; i<4; i++){
            ll nx = x+dx[i], ny=y+dy[i];
            if(in_bound(nx,ny) && grid[nx][ny] != '#' && mintimemy[nx][ny]>mintimemy[x][y]+1){
                mintimemy[nx][ny] = mintimemy[x][y]+1;
                parent[nx][ny] = {x,y};
                if(is_boundary(nx,ny) && mintime[nx][ny]>mintimemy[nx][ny]){
                    endp = {nx,ny};
                    return true;
                } else if(mintime[nx][ny]>mintimemy[nx][ny]){
                    q.push({nx,ny});
                }
                
            }
        }
    }
    return false;
}

string recon(){
    string revans = "";
    pair<ll,ll> k = endp;
    while(k!=start){
        ll x = k.F, y=k.S;
        pair<ll,ll> P = parent[x][y];
        ll px = P.F, py = P.S;
        for(ll i=0; i<4; i++){
            if(x - dx[i] == px && y- dy[i] == py){
                revans += dir[i];
                k = {px,py};
                break;
            }
        }
    }
    reverse(revans.begin(),revans.end());
    return revans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    grid.resize(n);
    for(ll i=0; i<n; i++){
        cin >> grid[i];
        for(ll j=0; j<m; j++){
            if(grid[i][j]=='A') start = {i,j};
            if(grid[i][j]=='M') monsters.push_back({i,j});
        }
    }
    if (is_boundary(start.F, start.S)) {
        cout << "YES\n0\n\n";
        return 0;
    }

    minmon();
    if(bfs()){
        cout << "YES\n";
        string ans = recon();
        ll o = ans.size();
        cout << o << '\n';
        cout << ans << '\n';
    } else{
        cout << "NO\n";
    }
}

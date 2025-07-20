#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef map<ll,ll> mll;
typedef set<ll> sll;
#define ain(a,n) for(ll lambda=0; lambda<n; lambda++){cin >> a[lambda];}
#define aout(a,n) for(ll _=0; _<n; _++){cout << a[_] << ' '}
#define F first
#define S second 
const ll N=1000;
ll n,m;
bool visited[N][N];
vector<string> grid;
pair<ll,ll> start,endp, parent[N][N];

ll dx[] = {1,0,-1,0};
ll dy[] = {0,1,0,-1};
char dir[] = {'D','R','U','L'};

bool in_bound(ll x, ll y){
    return x>=0 && x<n && y>=0  && y<m;
}

bool bfs(){
    queue<pair<ll,ll>> q;
    q.push(start);
    visited[start.F][start.S] = true;
    while(!q.empty()){
        pair<ll,ll> curr = q.front();q.pop();
        ll x = curr.F, y = curr.S;
        if(curr == endp) return true;

        for(ll i=0; i<4; i++){
            ll cx = x + dx[i], cy = y + dy[i];
            if( in_bound(cx,cy) && !visited[cx][cy] && grid[cx][cy] != '#'){
                visited[cx][cy] = true;
                q.push({cx,cy});
                parent[cx][cy] = curr;
            }
        }
    }
    return false;
}

string backtrack(){
    string revans = "";
    ll x = endp.F, y=endp.S;
    while(make_pair(x,y) != start){
        ll px = parent[x][y].F, py = parent[x][y].S;
        for(ll i=0; i<4; i++){
            if(x - dx[i] == px && y - dy[i] == py){
                revans += dir[i];
                break;
            }
        }
        x = px; y=py;
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
            if(grid[i][j] == 'A') start = {i,j};
            if(grid[i][j] == 'B') endp = {i,j};
        }
    }
    if(bfs()){
        cout << "YES\n";
        string ans = backtrack();
        ll k = ans.size();
        cout << k << '\n';
        cout << ans << '\n';
    } else {
        cout << "NO\n";
    }
}


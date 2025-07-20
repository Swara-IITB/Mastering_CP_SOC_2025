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

ll const N = 1e5+5;
vll adj[N];
bool visited[N];
ll team[N]={};
ll n,m;

bool bfs(ll c){
    queue<ll> q;
    q.push(c);
    team[c] = 1;
    while(!q.empty()){
        ll k=q.front(); q.pop();
        for(auto x : adj[k]){
            if(!visited[x]){
                visited[x]=true;
                q.push(x);
            }
            if(team[x]!=0 && team[x]==team[k]){
                return false;
            } else{
                team[x]=(team[k]==1)? 2 : 1;
            }
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool valid = true;
    cin >> n >> m;
    for(ll i=0; i<m; i++){
        ll x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(ll i=1; i<=n; i++){
        if(!visited[i]){
            if(!bfs(i)){
                valid = false;
                cout << "IMPOSSIBLE\n";
                break;
            }
        }
    }
    if(valid){
        for(ll i=1; i<=n; i++){
            cout << team[i] << '\n';
        }
    }
}

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
vector<vll> adj;
vll dist;
vector<bool> visited;
void dfs(ll i){
    visited[i]=true;
    for(auto u : adj[i]){
        if( visited[u]) continue;
        dist[u] = dist[i]+1;
        dfs(u);
    }
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    adj.resize(n+1);
    dist.resize(n+1);
    visited.resize(n+1,false);
    dist[1]=0;
    for(ll i=1; i<n; i++){
        ll a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    ll m=0,c=1;
    for(ll i=1; i<=n; i++){
        if(dist[i]>m) {
            m=dist[i];
            c=i;
        }
    }
    fill(visited.begin(), visited.end(), false);
    fill(dist.begin(), dist.end(), 0);
    dist[c]=0;
    dfs(c);
    m=0;
    for(ll i=1; i<=n; i++){
        m = max(m,dist[i]);
    }
    cout << m << '\n';
}

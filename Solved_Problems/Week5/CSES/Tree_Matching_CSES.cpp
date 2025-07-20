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
vector<vll> dist;
void dfs(ll i, ll par){
    for(ll u: adj[i]){
        if(u==par) continue;
        dfs(u,i);
    }
    ll total=0;
    for(auto u : adj[i]){
        if(u==par) continue;
        total+=max(dist[u][0],dist[u][1]);
    }
    dist[i][0] = total;

    for(auto u : adj[i]){
        if(u==par) continue;
        ll matched = 1 + dist[u][0] + (total - max(dist[u][0],dist[u][1]));
        dist[i][1] = max(dist[i][1],matched);
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    adj.resize(n+1);
    dist.resize(n+1,vll(2,0));
    
    for(ll i=1; i<n; i++){
        ll a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,-1);
    cout << max(dist[1][0],dist[1][1]);
}

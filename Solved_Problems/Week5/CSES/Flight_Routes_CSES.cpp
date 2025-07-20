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
const ll INF=1e18;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m,k;
    cin >> n >> m >> k;
    vector<vll> dist(n+1);
    vector<vector<pair<ll,ll>>> adj(n+1);
    for(ll i=0; i<m; i++){
        ll a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
    q.push({0,1});
    while(!q.empty()){
        ll d,node;
        tie(d,node) = q.top(); q.pop();
        if(dist[node].size()>=k) continue;
        dist[node].push_back(d);
        for(auto u : adj[node]){
            ll nnode = u.F, c = u.S;
            if(dist[nnode].size()<k){
                q.push({d+c,nnode});
            }
        }
    }
    aout(dist[n],k);
    cout << '\n';

}

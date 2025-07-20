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
const ll INF = 1e18;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m;
    cin >> n >> m;
    vector<vector<pair<ll,ll>>> adj(n+1);
    vector<vll> dist(n+1,vll(2,INF));
    dist[1][0] = 0;
    for(ll i=0; i<m; i++){
        ll a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
    priority_queue<tuple<ll,ll,ll>,vector<tuple<ll,ll,ll>>, greater<tuple<ll,ll,ll>>> q;
    q.push({0,1,0});
    while(!q.empty()){
        ll d,node,state;
        tie(d,node,state) = q.top(); q.pop();
        if(d>dist[node][state]) continue;

        for(auto u : adj[node]){
            ll nnode = u.F, c = u.S;
            if(dist[nnode][state] > d+c){
                dist[nnode][state] = d+c;
                q.push({dist[nnode][state],nnode,state});
            }
            if(state==0 && dist[nnode][1] > d+(c/2)){
                dist[nnode][1] = d+(c/2);
                q.push({dist[nnode][1],nnode,1});
            }
        }
    }
    cout << dist[n][1] << '\n';
}

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
ll n,m, INF=LLONG_MAX;
const ll N = 1e5+5;
vector<vector<pair<ll,ll>>> adj;
bool processed[N];
vll dist;
void dijkstra(){
    priority_queue<pair<ll,ll>> q;
    q.push({0,1});
    while(!q.empty()){
        ll a = q.top().S; q.pop();
        if(processed[a]) continue;
        processed[a]=true;
        for(auto u : adj[a]){
            ll b = u.F, c = u.S;
            if(dist[b]>dist[a]+c){
                dist[b]= dist[a]+c;
                q.push({-dist[b],b});
            }
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    dist.resize(n+1,INF);
    dist[1]=0;
    adj.resize(n+1);
    for(ll i=0; i<m; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
    dijkstra();
    for(ll i=1; i<=n; i++){
        cout << dist[i] << ' ';
    }
    cout << '\n';

}

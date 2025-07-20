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
    vector<tuple<ll,ll,ll>> edges(m);
    vll dist(n+1,-INF);
    dist[1]=0;
    vector<bool> incycle(n+1,false);
    for(ll i=0; i<m; i++){
        ll a,b,w;
        cin >> a >> b >> w;
        edges[i] = {a,b,w};
    }
    for(ll i=1; i<=n-1; i++){
        for(auto e : edges){
            ll a,b,w;
            tie(a,b,w) = e;
            if(dist[a]== -INF) continue;
            dist[b] = max(dist[b],dist[a]+w);
        }
    }
    ll ans = dist[n];
    for(ll i=1; i<=n; i++){
        for(auto e : edges){
            ll a,b,w;
            tie(a,b,w) = e;
            if(dist[a]!=-INF && dist[b] < dist[a]+w){
                dist[b] = dist[a]+w;
                incycle[b] = true;
            }
            if(incycle[a]) incycle[b] = true;
        }
    }
    if(incycle[n]) cout << -1 << '\n';
    else cout << ans << '\n';

}

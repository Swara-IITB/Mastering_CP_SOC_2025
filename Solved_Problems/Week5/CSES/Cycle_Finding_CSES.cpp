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
const ll INF = 1e15;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m;
    cin >> n >> m;
    vector<tuple<ll,ll,ll>> edges(m);
    vll dist(n+1,INF),parent(n+1,-2);
    dist[1]=0;
    
    for(ll i=0; i<m; i++){
        ll a,b,w;
        cin >> a >> b >> w;
        edges[i] = {a,b,w};
    }
    ll x=-1;
    for(ll i=1; i<=n; i++){
        x = -1;
        for(auto e : edges){
            ll a,b,w;
            tie(a,b,w) = e;
            if(dist[b] > dist[a]+w){
                dist[b] = max(-INF, dist[a] + w);
                parent[b] = a;
                x = b;
            }
        }
    }
    if(x == -1) cout << "NO\n";
    else {    
        for(ll i=0; i<n; i++) x = parent[x];
        vll cycle;
        cycle.push_back(x);
        ll k=parent[x];
        while(k!=x){
            cycle.push_back(k);
            k=parent[k];
        }
        cycle.push_back(k);
        reverse(cycle.begin(),cycle.end());
        cout << "YES\n";
        ll s = cycle.size();
        aout(cycle,s);
    }

}

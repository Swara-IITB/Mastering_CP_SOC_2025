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
    ll qu,n,m;
    cin >> n >> m >> qu;
    vector<vll> adj(n+1,vll(n+1,INF));
    for(ll i=0; i<m; i++){
        ll a,b,c;
        cin >> a >> b >> c;
        adj[a][b] = adj[b][a] = min(c,adj[a][b]);
    }
    for(ll i=1; i<=n; i++){
        adj[i][i]=0;
    }
    for (ll k = 1; k <= n; k++) {
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= n; j++) {
                if (adj[i][k] < INF && adj[k][j] < INF) {
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
    }

    for(ll i=0; i<qu; i++){
        ll x,y;
        cin >> x >> y;
        if(adj[x][y]!=INF){
            cout << adj[x][y] << '\n';
        } else{
            cout << -1 << '\n';
        }
    }
}

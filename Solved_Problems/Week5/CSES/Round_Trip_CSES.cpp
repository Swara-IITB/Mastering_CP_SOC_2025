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
bool visited[N]={};
ll parent[N]={};
ll n,m;

ll dfs(ll st){
    visited[st] = true;
    for(auto u : adj[st]){
        if(u==parent[st]) continue;
        if(visited[u]){
            parent[u] = st;
            return u;
        } else{
            parent[u]=st;
            ll c = dfs(u);
            if(c==0) continue;
            else return c;
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool valid = false;
    cin >> n >> m;
    for(ll i=0; i<m; i++){
        ll x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(ll i=1; i<=n; i++){
        if(!visited[i]){
            ll ans = dfs(i);
            if(ans!=0){
                vll out;
                out.push_back(ans);
                ll k=parent[ans];
                while(k!=ans){
                    out.push_back(k);
                    k = parent[k];
                }
                out.push_back(ans);
                k = out.size();
                cout << k << '\n';
                aout(out,k);
                valid = true;
                break;
            }
        }
    }
    if(!valid) cout << "IMPOSSIBLE\n";
   
}

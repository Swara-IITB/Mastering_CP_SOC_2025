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
const ll INF=1e5+5;
ll n,m;
vector<vll> adj;
vll topo,state(INF,0);

bool dfs(ll i){
    state[i] = 1;
    for(auto u : adj[i]){
        if(state[u]==0){
            if(!dfs(u)) return false;
        } else if(state[u]==1) {
            return false;
        }
    }
    state[i]=2;
    topo.push_back(i);
    return true;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool valid=true;
    cin >> n >> m;
    adj.resize(n+1);
    for(ll i=0; i<m; i++){
        ll a,b ;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for(ll i=1; i<=n; i++){
        if(state[i]==0){
            if(!dfs(i)){
                valid = false;
                break;
            }
        }
    }
    if(valid){
        reverse(topo.begin(),topo.end());
        aout(topo,n);
    } else {
        cout << "IMPOSSIBLE\n";
    }
}

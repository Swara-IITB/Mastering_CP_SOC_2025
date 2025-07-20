#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef map<ll,ll> mll;
typedef set<ll> sll;
#define ain(a,n) for(ll lambda=0; lambda<n; lambda++){cin >> a[lambda];}
#define aout(a,n) for(ll _=0; _<n; _++){cout << a[_] << ' '}
#define F first
#define S second 
const ll N = 1e5+5;
vll adj[N];
bool visited[N];
sll s;

void dfs(ll st){
    if(visited[st]) return;
    visited[st] = true;
    for(auto x : adj[st]){
        dfs(x);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m,ans=0; 
    cin >> n >> m;
    
    for(ll i=0; i<m; i++){
        ll x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(ll i=1; i<=n; i++){
        if(!visited[i]){
            ans++;
            dfs(i);
            s.insert(i);
        }
    }
    cout << ans-1 << '\n';
    for(auto it = s.begin(); next(it) != s.end(); it++ ){
        ll curr = *it;
        ll nc = *next(it);
        cout << curr << ' ' << nc << '\n';
    }
}

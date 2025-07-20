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
bool visited[N];
ll parent[N];
ll n,m;

bool bfs(){
    queue<ll> q;
    q.push(1);
    while(!q.empty()){
        ll k = q.front();
        q.pop();
        if(k==n) return true;
        for(auto x : adj[k]){
            if(!visited[x]){
                visited[x]=true;
                parent[x] = k;
                q.push(x);
            }
        }

    }
    return false;
}
vll recon(){
    vll revans;
    revans.push_back(n);
    ll k=n;
    while(k!=1){
        revans.push_back(parent[k]);
        k = parent[k];
    }
    reverse(revans.begin(),revans.end());
    return revans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(ll i=0; i<m; i++){
        ll x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    if(bfs()){
        vll ans = recon();
        ll an = ans.size();
        cout << an << '\n';
        aout(ans,an);
    } else{
        cout << "IMPOSSIBLE\n"; 
    }
}

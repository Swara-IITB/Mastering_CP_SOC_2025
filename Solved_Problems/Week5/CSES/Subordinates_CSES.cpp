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
ll n;
vector<vll> adj;
vll emp;

void dfs(ll i){
    for(auto u : adj[i]){
        dfs(u);
        emp[i]+=(emp[u]+1);
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    emp.resize(n+1);
    adj.resize(n+1);
    for(ll i=2; i<=n; i++){
        ll x;
        cin >> x;
        adj[x].push_back(i);
    }
    dfs(1);
    for(ll i=1; i<=n; i++){
        cout << emp[i] << ' ';
    }
    cout << '\n';
}

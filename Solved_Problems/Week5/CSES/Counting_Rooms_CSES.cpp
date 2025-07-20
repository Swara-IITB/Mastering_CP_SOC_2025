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

void dfs(ll i,ll j, vector<vector<char>>& a,vector<vll>& v,ll n, ll m){
    v[i][j] = 1;
    if(i-1 >=0) if(a[i-1][j]=='.' && v[i-1][j]==0){dfs(i-1,j,a,v,n,m);}
    if(i+1 <n) if(a[i+1][j]=='.' && v[i+1][j]==0){dfs(i+1,j,a,v,n,m);}
    if(j-1 >=0) if(a[i][j-1]=='.' && v[i][j-1]==0){dfs(i,j-1,a,v,n,m);}
    if(j+1 <m) if(a[i][j+1]=='.' && v[i][j+1]==0){dfs(i,j+1,a,v,n,m);}
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m,ans=0;
    cin >> n >> m;
    vector<vector<char>> a(n,vector<char>(m));
    vector<vll> visited(n,vll(m,2));
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            cin >> a[i][j];
            if(a[i][j] == '.'){
                visited[i][j] = 0;
            }
        }
    }
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            if(a[i][j] == '.' && visited[i][j]==0){
                dfs(i,j,a,visited,n,m);
                ans++;
            }
        }
    }
    cout << ans << '\n';
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll u, ll v){ 
    ll a = max(u,v), b = min(u,v);
    if(!b) return abs(a);
    return gcd(b,a%b);
}

ll modpow(ll x, ll n, ll m){
    if(n==0) return 1;
    ll u = modpow(x,n/2,m);
    u =( u*u )% m;
    if(n%2) u = (u*x) % m;
    return u;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll x,n;
    cin >> x >> n;
    vector<ll> coins(x);
    for(ll i=0; i<x; i++){
        cin >> coins[i];
    }
    const ll INF = 1e18;
    vector<ll> minways(n+1);
    minways[0] = 0;
    for(ll i=1; i<=n; i++){
        minways[i] = INF;
        for(auto u : coins){
            if(i-u>=0) minways[i] = min(minways[i],minways[i-u]+1);
        }
    }
    if(minways[n] == INF) cout << -1 << '\n';
    else cout << minways[n] << '\n';
}

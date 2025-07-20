#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll u, ll v){ 
    ll a = max(u,v), b = min(u,v);
    if(!b) return abs(a);
    return gcd(b,a%b);
}
const ll M = 1e9+7;
ll binpow(ll x, ll n, ll m){
    ll res = 1;
    while(n>0){
        if(n&1){
            res = res*x%M;
        }
        x = x*x%M;
        n >>=1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m,ans;
    cin >> n >> m;
    for(ll i=1; i<=n; i++){
        ans = (ans + binpow(m,gcd(i,n),M)) % M;
    }
    ans = (ans * binpow(n,M-2,M)) % M;
    cout << ans << '\n';
}

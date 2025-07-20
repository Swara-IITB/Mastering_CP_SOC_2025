#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


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
    ll n,ans;
    cin >> n ;
    ll ns = n*n;
    ans = binpow(2,ns, M) ;
    if(ns%2){
        ans = ((ans + (binpow(2,(ns+3)/4,M) * 2))% M + binpow(2,((ns-n)/2)+((n+1)/2),M)) % M;
    } else {
        ans = ((ans + (binpow(2,(ns)/4,M) * 2)) % M + binpow(2,ns/2,M)) % M;
    }
    ans = (ans * binpow(4,M-2,M)) % M;
    cout << ans << '\n';
}

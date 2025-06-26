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

ll binpow(ll x, ll n, ll m){
    ll res = 1;
    while(n>0){
        if(n&1){
            res = res*x;
        }
        x = x*x;
        n >>=1;
    }
    return res;
}
const int N = 1e6+5;
const ll M = 1e9+7;

ll fact[N], invfact[N];

void precompute(){
    fact[0] = invfact[0] = 1;
    for(ll i = 1; i < N; ++i){
        fact[i] = (fact[i-1] * i) % M;
    }
    invfact[N-1] = binpow(fact[N-1], M-2, M);
    for(ll i = N-2; i >= 1; --i){
        invfact[i] = (invfact[i+1] * (i+1)) % M;
    }
}

ll BinCoeff(ll a, ll b){
    if(b < 0 || b > a) return 0;
    return fact[a] * invfact[b] % M * invfact[a-b] % M;
}
ll der[N];
ll Derangements(ll n, ll M){
    der[0]=1; der[1]=0;
    for(ll i=1; i<n; i++){
        der[i+1]=((i)*((der[i]+der[i-1])%M))% M;
    }
    return der[n];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    cout << Derangements(n,M) << '\n';
    
}

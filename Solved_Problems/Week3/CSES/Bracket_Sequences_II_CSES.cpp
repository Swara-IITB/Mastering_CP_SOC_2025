#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6+5;
const ll M = 1e9+7;

ll fact[N], invfact[N];

// Binary exponentiation
ll binpow(ll x, ll n, ll m){
    ll res = 1;
    while(n > 0){
        if(n & 1) res = res * x % m;
        x = x * x % m;
        n >>= 1;
    }
    return res;
}

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


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    precompute();
    ll n;
    cin >> n;
    if(n%2!=0) {cout << 0<< '\n'; return 0;}
    string s;
    cin >> s;
    ll k=s.size(), del=0,a,b;
    for(ll i=0; i<k; i++){
        if(s[i]=='('){ del++;a++;}
        else {del--; b++;}
        if(del<0){cout << 0 << '\n'; return 0;}
    }
    a = (n/2)-a;
    ll ans = (BinCoeff(n-k,a) - BinCoeff(n-k,a-1) + M) % M;
    cout << ans << '\n';
}

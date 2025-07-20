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
    freopen("sumdiv.in","r",stdin);
    freopen("sumdiv.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll a,b, m=1e9 + 7, num=1, deno=1;
    cin >> a >> b;
    map<ll,ll> f;
    for(ll i=2; i*i<=a; i++){
        while(a%i==0){
            f[i]++;
            a /= i;
        }
    }
    if(a != 1) f[a]=1;
    for(auto u : f){
        num = (num * ( modpow(u.first,((u.second*b)+1)%(m-1),m)-1+m))%m;
        deno = (deno * (u.first-1))%m;
    }
    ll ans = (num*modpow(deno,m-2,m))%m;
    cout << ans << '\n'; 
}

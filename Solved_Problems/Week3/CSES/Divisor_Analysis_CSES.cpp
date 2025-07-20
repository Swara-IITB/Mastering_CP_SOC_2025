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
    ll t,num=1,sum=0,pro=1,m=1e9+7,deno=1,upon=1;
    cin >> t;
    vector<pair<ll,ll>> a;
    while(t--){
        ll x,y,xy;
        cin >> x >> y;
        a.push_back({x,y});
        num =(num *(y+1))%m;
        deno = (deno*(x-1))%m;
        upon = (upon*(modpow(x,y+1,m)*x-1+m))%m;
    }
    sum = (upon*modpow(deno,m-2,m))%m;
    
}

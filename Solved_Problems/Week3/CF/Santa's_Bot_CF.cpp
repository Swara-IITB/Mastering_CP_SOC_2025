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
void addf(ll x1, ll y1, ll x2, ll y2, ll &x, ll&y){
    x = (x1*y2)+(x2*y1);
    y = y1*y2;
    ll g = gcd(x,y);
    x = x/g; y=y/g;
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m=998244353,k;
    cin >> n;
    k=n;
    ll num=0,deno=1;
    map<ll,ll> cnt;
    vector<vector<ll>> a; 
    while(k--){
        ll x,y;
        cin >> x;
        vector<ll> temp(x);
        for(ll i=0; i<x; i++){
            cin >> y;
            cnt[y]++;
            temp[i] = y;
        }
        a.push_back(temp);
    }
    for(ll i=0; i<n; i++){
        for(ll j=0; j<a[i].size(); j++){
            addf(num,deno,cnt[a[i][j]], a[i].size(),num,deno);
        }
    }
    
    ll g = gcd(num,deno),x=(num/g)%m,y=(deno/g)%m;
    y = modpow(y,m-2,m);
    ll ans = (x*y)%m;
    cout << ans << '\n';
}

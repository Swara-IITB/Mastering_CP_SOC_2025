#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
    ll t,m= 1e9+7;
    cin >> t;
    while(t--){
        ll a,b,c,bc,ans;
        cin >> a >> b >> c;
        bc = modpow(b,c,m-1);
        ans = modpow(a,bc,m);
        cout << ans << '\n';
    }
}

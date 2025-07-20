#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef map<ll,ll> mll;
typedef set<ll> sll;
#define ain(a,n) for(ll lambda=0; lambda<n; lambda++){cin >> a[lambda];}
#define aout(a,n) for(ll _=0; _<n; _++){cout << a[_] << ' ';}
#define F first
#define S second 

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
    ll t;
    cin >> t;
    while(t--){

    }
}

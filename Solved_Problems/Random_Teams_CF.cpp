#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll u, ll v){ 
    ll a = max(u,v), b = min(u,v);
    if(!b) return abs(a);
    return gcd(b,a%b);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m, kmin, kmax;
    cin >> n >> m;
    kmax = (n - (m-1))*(n-m)/2;
    kmin = ((n/m)*(n/m - 1)/2 * (m - (n%m))) + ((n/m)*(n/m + 1)/2 * (n%m));
    cout << kmin << " " << kmax << '\n';
}

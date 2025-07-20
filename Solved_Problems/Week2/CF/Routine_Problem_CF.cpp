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
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    if(c*b > d*a){
        ll n = c*a/gcd(a,c);
        b = b*n/a; d = d*n/c;
        cout << (b-d)/gcd(b,d) << "/" << b/gcd(b,d)<< '\n';
    } else if(c*b < d*a){
        ll n = d*b/gcd(d,b);
        a = a*n/b; c = c*n/d;
        cout << (a-c)/gcd(a,c) << "/" << a/gcd(a,c)<< '\n';
    } else cout << 0 << "/" << 1 << '\n';
}

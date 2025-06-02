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
    ll t;
    cin >> t;
    while(t--){
        ll n,x,ans;
        bool valid=true;
        cin >> n;
        vector<ll> a;
        for ( ll i =0; i < 4*n ; i++){
            cin >> x;
            a.push_back(x);
        }
        sort(a.begin(),a.end());
        ans = a[0] * a[4*n-1];
        for(ll i =0; i< 2*n ; i++){
            if(i%2 == 0){
                if(a[i]!=a[i+1] || a[4*n-i-1]!=a[4*n-i-2]){
                    valid = false;
                    break;
                }
            }
            if(ans != a[i]*a[4*n-i-1]){
                valid = false;
                break;
            }
        }
        if(valid) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}

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
        ll n,k,x;
        bool valid = true;
        cin >> n >> k;
        vector<ll> a;
        set<ll> s;
        for(ll i=0; i<n ; i++){
            cin >> x;
            if(x>n) valid = false;
            s.insert(x);
        }
        if(s.size()>k) valid = false;
        if(!valid){
            cout << -1 << '\n';
            continue;
        } else{
            for(auto b : s){
                a.push_back(b);
            }
            if(a.size()<k) a.resize(k,a[0]);
            cout << k*n << '\n';
            for(ll i=0; i<n; i++){
                for(auto b : a) cout << b << " ";
            }
            cout << '\n';
        }
    }
}

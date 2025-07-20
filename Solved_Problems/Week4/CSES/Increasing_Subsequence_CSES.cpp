#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> a(n),dp;
    for(ll i=0; i<n; i++){
        cin >> a[i];
    }
    for(auto x : a){
        auto it = lower_bound(dp.begin(),dp.end(),x);
        if(it == dp.end()){
            dp.push_back(x);
        } else{
            *it = x;
        }
    }
    ll ans = dp.size();
    cout << ans << '\n';
}

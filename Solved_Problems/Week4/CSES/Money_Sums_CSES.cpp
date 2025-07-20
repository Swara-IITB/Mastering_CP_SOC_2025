#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,sum=0;
    cin >> n;
    vector<ll> a(n);
    for(ll i=0; i<n; i++){
        cin >> a[i] ;
        sum += a[i];
    }
    vector<bool> dp(sum+1,false);
    dp[0] = true;
    for( auto u : a){
        for(ll i=sum; i>=0; i--){
            if(dp[i]){
                dp[i+u] = true;
            }
        }
    }
    vector<ll> ans;
    for(ll i=1; i<=sum; i++){
        if(dp[i]) ans.push_back(i);
    }
    cout << ans.size() << '\n';
    for(auto u : ans) cout << u << ' ';
    cout << '\n';
}
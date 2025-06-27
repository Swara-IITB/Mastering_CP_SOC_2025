#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,x;
    cin >> n >> x;
    vector<ll> h(n), s(n);
    for(ll i=0; i<n; i++) cin >> h[i];
    for(ll i=0; i<n; i++) cin >> s[i];
    vector<ll> dp(x+1,0);
    dp[0] = 0;
    for(ll i=0; i<n; i++){
        for(ll j=x; j>=h[i]; j--){
            dp[j] = max(dp[j], dp[j-h[i]]+s[i]);
        }
    }
    cout << dp[x] << '\n';
}

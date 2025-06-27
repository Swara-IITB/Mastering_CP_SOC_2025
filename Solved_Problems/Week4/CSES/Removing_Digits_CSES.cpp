#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> dp(n+1,1e9);
    dp[0]=0;
    for(ll i=1; i<=n; i++){
        ll x = i;
        while(x>0){
            ll d = x%10;
            x /= 10;
            if(d==0) continue;
            dp[i] = min(dp[i],dp[i-d]+1);
        }
    }
    cout << dp[n] << '\n';
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll const M = 1e9+7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    ll sum = n*(n+1)/2;
    if(sum%2) cout << 0 << '\n';
    else{
        ll t = sum/2;
        vector<ll> dp(t+1,0);
        dp[0]=1;
        for(ll i=1; i<=n; i++){
            for(ll j=t; j>=i; j--){
                dp[j] = (dp[j] + dp[j-i]) % M;
            }
        }
        ll inv = (M+1)/2;
        cout << (dp[t]*inv) % M << '\n';
    }
}
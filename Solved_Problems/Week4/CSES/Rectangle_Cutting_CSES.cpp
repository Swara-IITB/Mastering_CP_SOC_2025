#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m;
    cin >> n >> m;
    vector<vector<ll>> dp(n+1,vector<ll>(m+1,1e9));
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=m; j++){
            if(i==j){
                dp[i][j] = 0;
            } else{
                for(ll k=1; k<i; k++){
                    dp[i][j] = min(dp[i][j], dp[i-k][j] + dp[k][j] + 1);
                }
                for(ll k=1; k<j; k++){
                    dp[i][j] = min(dp[i][j], dp[i][j-k] + dp[i][k] + 1);
                }
            }
        }
    }
    cout << dp[n][m] << '\n';
}

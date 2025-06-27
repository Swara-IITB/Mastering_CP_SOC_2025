#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll const M = 1e9+7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<vector<ll>> dp(n,vector<ll>(n,0));
    dp[0][0] = 0;
    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            char c;
            cin >> c;
            if(c != '*'){
                if(i==0 && j==0){
                    dp[0][0] = 1;
                    continue;
                }
                if(i==0) dp[i][j] = dp[i][j-1];
                else if(j==0) dp[i][j] = dp[i-1][j];
                else dp[i][j] = (dp[i-1][j] + dp[i][j-1] )%M;
            }

        }
    }
    cout << dp[n-1][n-1] << '\n';
}

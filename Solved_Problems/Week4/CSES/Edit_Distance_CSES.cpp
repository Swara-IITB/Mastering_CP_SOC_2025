#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a,b;
    cin >> a >> b;
    ll n=a.size(), m=b.size();
    vector<vector<ll>> dp(n+1,vector<ll>(m+1));
    for(ll i=0; i<=n; i++){ dp[i][0] = i;}
    for(ll i=0; i<=m; i++){ dp[0][i] = i; }

    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=m; j++){
            if(a[i-1]==b[j-1]){
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = min({dp[i-1][j-1]+1, dp[i-1][j]+1, dp[i][j-1]+1});
            }
        }
    }
    cout << dp[n][m] << '\n';
}

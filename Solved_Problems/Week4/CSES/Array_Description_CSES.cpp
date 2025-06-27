#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll const M = 1e9+7;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m;
    cin >> n >> m;
    vector<vector<ll>> dp(n+1,vector<ll>(m+1,0));
    ll p; cin >> p;
    if(p==0) for(ll i=1; i<=m; i++) dp[1][i]=1;
    else dp[1][p] = 1;
    for(ll i=2; i<=n; i++){
        ll v ;
        cin >> v;
        if(v==0){
            for(ll j=1; j<=m; j++){
                if(j-1!=0) dp[i][j]=(dp[i][j]+dp[i-1][j-1])%M;
                if(j+1!=m+1) dp[i][j]=(dp[i][j]+dp[i-1][j+1])%M;
                dp[i][j]=(dp[i][j] + dp[i-1][j])%M;
            }
        } else{
            if(v-1!=0) dp[i][v]=(dp[i][v]+dp[i-1][v-1])%M;
            if(v+1!=m+1) dp[i][v]=(dp[i][v]+dp[i-1][v+1])%M;
            dp[i][v]=(dp[i][v] + dp[i-1][v])%M;
        } 
    }
    ll ans=0;
    for(ll i=1; i<=m; i++){
        ans = (ans + dp[n][i])%M;
    }
    cout << ans << '\n';
}

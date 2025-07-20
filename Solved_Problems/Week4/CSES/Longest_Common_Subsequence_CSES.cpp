#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m;
    cin >> n >> m;
    vector<ll> a(n),b(m);
    for(ll i=0; i<n; i++){ cin >> a[i]; }
    for(ll i=0; i<m; i++){ cin >> b[i]; }
    vector<vector<ll>> dp(n+1,vector<ll>(m+1));
    for(ll i=0; i<=n; i++){ dp[i][0] = 0;}
    for(ll i=0; i<=m; i++){ dp[0][i] = 0;}

    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=m; j++){
            if(a[i-1]==b[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            } else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    ll ans = dp[n][m]; 
    vector<ll> c(ans);
    ll i=n, j=m;
    while(ans){
        if(a[i-1]==b[j-1]){
            c[--ans] = a[i-1];
            i--; j--;
        } else {
            if(dp[i-1][j]>=dp[i][j-1]){
                i--;
            } else{
                j--;
            }
        }
    }
            
       
    cout << dp[n][m] << '\n';
    for(ll k=0; k<c.size(); k++){
        cout << c[k] << ' ';
    }
    cout << '\n';
}

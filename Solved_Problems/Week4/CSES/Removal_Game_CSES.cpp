#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,sum=0;
    cin >> n;
    vector<ll> x(n);
    vector<vector<ll>> dp(n,vector<ll>(n));
    for(ll i=0; i < n; i++){
        cin >> x[i];
        dp[i][i] = x[i];
        sum+=x[i];
    }
    for(ll i=1; i<n; i++){
        for(ll j=0; j<n-i; j++){
            dp[j][j+i] = max(x[j]-dp[j+1][j+i],x[j+i]-dp[j][j+i-1]);
        }
    }
    cout << (sum+dp[0][n-1])/2 << '\n';
}
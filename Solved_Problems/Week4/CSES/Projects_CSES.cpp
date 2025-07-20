#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<tuple<ll,ll,ll>> v;
    vll dp(n);
    for(ll i=0; i<n; i++){
        ll a, b, p;
        cin >> a >> b >> p;
        v.push_back({b,a,p});
    }
    sort(v.begin(),v.end());
    dp[0] = get<2>(v[0]);
    ll ans=dp[0];
    for(ll i=1; i<n; i++){
        ll m=0;
        for(ll j=0; j<i; j++){
            if(get<0>(v[j]) < get<1>(v[i])){
                m=max(m,dp[j]+get<2>(v[i]));
            } else{
                break;
            }
        }
        if(m==0) dp[i] = get<2>(v[i]);
        else dp[i] = m;
        ans = max(ans,dp[i]);
    }
    cout << ans << '\n';
}

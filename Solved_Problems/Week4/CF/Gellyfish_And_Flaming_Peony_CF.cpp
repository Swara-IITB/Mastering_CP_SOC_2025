#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n,ans=0,m;
        cin >> n;
        vector<ll> a(n);
        for(ll i=0; i<n; i++){cin >> a[i];}
        m=a[n-1];
        for(ll i=n-2; i>=0; i--){
            if(a[i]<=m){
                m = a[i];
            }else{
                ll x = ((a[i]+m-1)/m);
                ans +=(x-1);
                m = a[i]/x;
            }
        }
        cout << ans << '\n';
    }
}

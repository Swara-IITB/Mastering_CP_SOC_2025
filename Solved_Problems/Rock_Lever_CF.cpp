#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> a(n);
        for(ll i=0; i<n; i++){
            cin >> a[i];
        }
        sort(a.begin(),a.end());
        ll k=0,ans=0,p=1;
        while(a[0]>=p && a[0]>=p*2){
            p *= 2;
        }
        for(ll i=1; i<n; i++){
            if(a[i]>=p*2){
                while(a[i]>=p && a[i]>=p*2){
                    p *= 2;
                }
                k=0;
            } else {
                k++;
            }
            ans += k;
        }
        cout << ans << '\n';
    }
}

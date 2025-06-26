#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n, x, ans;
        cin >> n;
        cin >> ans;
        for(ll i=0; i<n-1; i++){
            cin >> x;
            ans &= x;
        }
        cout << ans << '\n';
    }
}
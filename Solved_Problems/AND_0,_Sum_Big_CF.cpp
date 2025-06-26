#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
       ll n,k, m=1000000007;
       cin >> n >> k;
       ll ans =n%m;
       for(ll i=0; i<k-1; i++){
        ans = (ans*n)%m;
       }
       cout << ans << '\n';
    }
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m,k,f,ans=0;
    cin >> n >> m >> k;
    vector<ll> a(m);
    for(ll i=0; i<m; i++){
        cin >> a[i];
    }
    cin >> f;
    for(ll i=0; i<m; i++){
        ll c = 0,t = a[i] ^ f;
        bool valid = true;
        for(ll j=0; j<n; j++){
            if( (t & (1<<j) )!= 0){
                c++;
            }
            if( c > k){
                valid = false;
                break;
            }
        }
        if(valid) ans++;
    }
    cout << ans << '\n';
    
}
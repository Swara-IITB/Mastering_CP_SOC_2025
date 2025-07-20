#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n,k,m,c=0,maxr=0;
        cin >> n >> k;
        map<ll,ll> a;
        a[0]=0;
        ll r = k;
        for(ll i = 0; i<n; i++){
            cin >> m;
            a[m%k]++;
        }
        if(a[0] == n) {
            cout << 0 << '\n';
            continue;
        }
        for(auto x : a){
            if(x.first == 0) continue;
            if(x.second == maxr){
                r = min(r,x.first);
            } else if(x.second > maxr){
                maxr = x.second;
                r = x.first;
            }
        }
        c = k*(maxr - 1) + k - r + 1;
        cout << c << "\n";
    }
    
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n,sec=1,x,y,ans=0;
        cin >> n;
        cin >> x;
        for(ll i=1; i<n; i++){
            cin >> y;
            
            while(y<x){
                y += sec;
                ans++;
                sec *= 2;
            }
            
            x = y;
        }
        cout << ans << '\n';
    }
}
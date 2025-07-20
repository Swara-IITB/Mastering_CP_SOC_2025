#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll l,r,ans=0;
        cin >> l >> r;
        while(l!=0){
            if((r-l)==0){
                ans+=2;
            }else if((r-l)==1){
                ans+=1;
            } 
            l/=10;
            r/=10;
        }
        cout << ans << '\n';
    }
}

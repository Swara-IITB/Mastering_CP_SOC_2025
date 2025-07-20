#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
       ll f,sum=0,ans=0,n=0;
       cin >> f;
       vector<ll> a(f);
       for(ll i=0; i<f; i++){
        cin >> a[i];
       }
       sort(a.begin(),a.end());
       reverse(a.begin(),a.end());
       for(ll i=0; i<f; i++){
        sum+=a[i];
        if(pow(4,n)==i+1){
            ans += sum;
            n++;
        }
       }
       cout << ans << '\n';
    
}

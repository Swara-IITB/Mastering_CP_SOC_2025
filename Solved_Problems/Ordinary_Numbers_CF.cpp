#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll t,n;
    cin >> t;
    while(t--){
        ll ans = 0;
        cin >> n;
        // keep dividing n by 1 , 11 ,111 and if the quotient is >= 9 count it as 9 if it is below 9 say 5 then count 5 and stop
        for(ll i = 1; n/i !=0; i=10*i+1){
            ans+=(n/i>=9)?9:n/i;
        }
        cout << ans << '\n';
    }
}
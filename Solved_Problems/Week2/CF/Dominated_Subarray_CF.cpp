#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll y;
    cin >> y ;
    while(y--){
        ll n,x;
        cin >> n;
        ll ans = n+1;
        map<ll,ll> a;
        for(ll i =1; i<=n; i++){
            cin >> x;
            if(a[x] == 0) a[x] = i;
            else {
                ans = min(ans, (i-a[x]+1));
                a[x] = i;
            }
        }
        if( ans == n+1) cout << -1 << '\n';
        else cout << ans << '\n';
    }
}
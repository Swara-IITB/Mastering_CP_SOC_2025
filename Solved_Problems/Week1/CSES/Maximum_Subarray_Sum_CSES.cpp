#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    cin >> n;
    vector<ll> arr(n), a(n);
    for(ll i = 0; i<n; i++){
        cin >> arr[i];
    }
    a[0]=arr[0];
    ll ans = a[0];
    for(ll i=0; i<n-1; i++){
        a[i+1] = max(arr[i+1], a[i]+arr[i+1]);
        ans = max(ans,a[i+1]);
    }
    cout << ans << '\n';
}
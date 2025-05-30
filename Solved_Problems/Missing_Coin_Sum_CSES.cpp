#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,sum=1;
    cin >> n;
    vector<ll> a(n);
    for(ll i =0; i<n; i++) cin >> a[i];
    sort(a.begin(),a.end());
    for(ll i =0; i<n ; i++){
        if(sum < a[i]) break;
        sum += a[i];
    }
    cout << sum << '\n';
}
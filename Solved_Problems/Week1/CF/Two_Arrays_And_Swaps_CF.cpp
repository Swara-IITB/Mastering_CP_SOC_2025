#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n, k,sum=0;
        cin >> n >> k;
        ll a[n], b[n];
        for(ll i=0; i<n; i++){
            cin >> a[i];
            sum+=a[i];
        }
        sort(a,a+n);
        for(ll i=0; i<n; i++){
            cin >> b[i];
        }
        sort(b,b+n);
        for(ll i=0; (i<k) && (a[i]<b[n-1-i]); i++){
            sum = sum - a[i] + b[n-1-i];
        }
        cout << sum<< '\n';
    }
}
    
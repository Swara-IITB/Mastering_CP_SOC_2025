#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,sum=0,maxi=0,x;
    cin >> n;
    for(ll i=0; i<n; i++){
        cin >> x;
        sum += x;
        maxi = max(x,maxi);
    }
    cout << max(sum,2*maxi) << '\n';
}

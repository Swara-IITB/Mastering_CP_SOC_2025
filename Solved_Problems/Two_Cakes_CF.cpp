#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,x,ans=0;
    cin >> n;
    vector<vector<ll>> a(n);
    for(ll i =0; i<2*n; i++){
        cin >> x; 
        a[x-1].push_back(i);
    }
    for(ll i =0; i<n-1; i++){
        ans+= min(abs(a[i][0]-a[i+1][0])+abs(a[i][1]-a[i+1][1]),abs(a[i][1]-a[i+1][0])+abs(a[i][0]-a[i+1][1]));
    }
    ans += a[0][0]+a[0][1];
    cout << ans<< '\n';
}

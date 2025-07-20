#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n,m,ans=0;
        cin >> n >> m;
        vector<vector<ll>> a(n);
        for(ll i = 0; i< n; i++ ){
            for(ll j =0; j<m; j++){
                ll x;
                cin >> x;
                a[i].push_back(x);
            }
        }
        for(ll i = 0; i<= n/2 -1; i++){
            for(ll j =0; j<= m/2-1; j++){
                vector<ll> temp;
                temp.push_back(a[i][j]);
                temp.push_back(a[i][m-j-1]);
                temp.push_back(a[n-1-i][j]);
                temp.push_back(a[n-1-i][m-1-j]);
                sort(temp.begin(),temp.end());
                ans += abs(temp[3]-temp[0]) + abs(temp[1]-temp[2]);
            }
        }
        if(m%2 !=0){
            for(ll i=0; i<n/2; i++){
                ans+= abs(a[i][m/2]-a[n-1-i][m/2]);
            }
        }
        if(n%2 !=0){
            for(ll j=0; j<m/2; j++){
                ans+= abs(a[n/2][j]-a[n/2][m-1-j]);
            }
        }
        cout << ans << '\n';
    }
}

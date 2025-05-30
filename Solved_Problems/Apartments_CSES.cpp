#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,m,k,x,ans=0;
    cin >> n >> m >> k;
    vector<ll> a,b;
    while(n--){
        cin >> x;
        a.push_back(x);
    }
    while(m--){
        cin >> x;
        b.push_back(x);
    }
    sort(a.begin(),a.end()); sort(b.begin(),b.end());
    auto itn = a.begin(), itm = b.begin();
    while(itn != a.end() && itm != b.end()){
        if((*itn)+k >= *itm && (*itn)-k <= *itm){
            ans++; itn++; itm++;
        } else if((*itn)-k > *itm){
            itm++;
        } else {
            itn++;
        }
    }
    cout << ans << '\n';
}
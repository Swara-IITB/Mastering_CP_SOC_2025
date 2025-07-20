#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,x,y,ans=0,ansmax=0;
    cin >> n;
    map<ll,ll> a;
    for(ll i =0; i<n; i++){
        cin >> x>>y;
        a[x] = 1;
        a[y]= 0;
    }
    for(auto i : a){
        if(i.second){
            ans++;
            ansmax = max(ansmax,ans);
        } else {
            ans--;
        }
    }
    cout << ansmax << '\n';
}
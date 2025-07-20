#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    map<ll,ll> a;
    ll x ;
    for(ll i=0; i<n; i++){
        cin >> x;
        ll p=1;
        while(x!=0){
            if(x%2){
                a[p]++;
            }
            x /= 2;
            p*=2;
        }
    }
    ll sum=0;
    for(ll i=0; i<n; i++){
        ll num =0;
        for(auto &u : a){
            if(u.second){
                num += u.first;
                u.second--;
            }
        }
        sum += num*num;
    }
    cout << sum << '\n';
}

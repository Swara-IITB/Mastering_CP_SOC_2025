#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll start(vector<ll>& mobius){ // initialise all the values of mobius with 1
    ll VALMAX = mobius.size(),ans = 1;
    
    for(ll i=2; i<VALMAX; i++){
        if(mobius[i]){
            mobius[i] = -mobius[i];
            for(ll j = 2*i; j<VALMAX; j+=i){
                mobius[j] += mobius[i];
            }
        } else ans++;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> v(n+1,1);
        cout << start(v) << '\n';
    }    
}
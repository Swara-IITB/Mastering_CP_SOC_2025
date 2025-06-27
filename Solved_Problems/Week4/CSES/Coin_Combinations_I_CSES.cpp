#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll const M = 1e9+7;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll x,n;
    cin >> x >> n;
    vector<ll> coins(x);
    for(ll i=0; i<x; i++){
        cin >> coins[i];
    }
    vector<ll> ways(n+1);
    ways[0] = 1;
    for(ll i=1; i<=n; i++){
        ways[i] = 0;
        for(auto u : coins){
            if(i-u>=0) ways[i] = (ways[i] + ways[i-u])%M;
        }
    }
    cout << ways[n] << '\n';
}

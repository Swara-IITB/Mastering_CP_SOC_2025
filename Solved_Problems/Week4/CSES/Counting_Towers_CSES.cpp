#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll const M = 1e9+7;
ll const N = 1e6+5;
ll dpa[N]={},dpb[N]={};
void start(){
    dpa[1]=dpb[1]=1;
    for(ll i=2; i<N; i++){
        dpb[i] = (dpa[i-1] + (4*dpb[i-1])%M)%M;
        dpa[i] = (dpb[i-1] + (2*dpa[i-1])%M)%M;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    start();
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        cout << (dpa[n]+dpb[n]) % M << '\n';
    }
}

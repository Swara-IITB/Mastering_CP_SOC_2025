#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll const M=1e9+7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    ll num[]={1,2,3,4,5,6};
    vector<ll> ways(n+1);
    ways[0]=1;
    for(ll i=1; i<=n; i++){
        ways[i]=0;
        for(auto u : num){
            if(i-u>=0) ways[i] = (ways[i] + ways[i-u]) %M ;
        }
    }
    cout << ways[n] % M<< '\n';
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,sum=0,x,sump=0,tsum=0;
    cin >> n;
    vector<ll> a;
    for(ll i=0; i<n; i++){
        cin >> x;
        a.push_back(x);
        cin >> x;
        sum += x;
    }
    sort(a.begin(),a.end());
    for(auto p : a){
        sump+=p;
        tsum+=sump;
    }
    cout << sum - tsum << '\n';
}
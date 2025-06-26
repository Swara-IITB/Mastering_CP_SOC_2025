#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef map<ll,ll> mll;
typedef set<ll> sll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<vll> v(3);
    for(ll i=0; i<n; i++){
        char c;
        cin >> c;
        if(c=='0') v[0].push_back(i);
        else if(c=='1') v[1].push_back(i);
        else v[2].push_back(i);
    }
    
}

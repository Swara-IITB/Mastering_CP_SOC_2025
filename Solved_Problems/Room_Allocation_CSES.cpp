#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool comp(tuple<ll,ll,ll> &a, tuple<ll,ll,ll> &b){
    if(get<0>(a)==get<0>(b)) return get<1>(a) < get<1>(b);
    return get<0>(a) < get<0>(b);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<tuple<ll,ll,ll>> a(n);
    for(ll i=0; i<n; i++){
        ll x,y;
        cin >> x >> y;
        a[i] = {x,y,i};
    }
    sort(a.begin(),a.end(),comp);
    vector<ll> alloc(n);
    alloc[get<2>(a[0])]=1;
    ll rn = 1;
    for(ll i=1; i<n; i++){
        bool done = false;
        for(ll j=0; j<=i-1; j++){
            if(get<0>(a[i])>=get<0>(a[j])&&get<0>(a[i])<=get<1>(a[j])){
                continue;
            } else{
                get<1>(a[j]) = get<1>(a[i]);
                alloc[get<2>(a[i])] = alloc[get<2>(a[j])];
                done = true;
                break;
            }
        }
        if(!done) alloc[get<2>(a[i])] = ++rn;
    }
    cout << rn << '\n';
    for(ll i=0; i<n; i++){
        cout << alloc[i] << ' ';
    }
    cout << '\n';
    
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool comp(tuple<ll,ll,ll> &a, tuple<ll,ll,ll> &b){
    if(get<0>(a)==get<0>(b)) return get<1>(a) > get<1>(b);
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
    vector<ll> contains(n), contained(n);
    ll mini = 2e9,maxi=0;
    for(ll i=n-1; i>=0; i--){
        if(get<1>(a[i])>=mini) contains[get<2>(a[i])]=1;
        mini = min(mini,get<1>(a[i]));
    }
    for(ll i=0; i<n; i++){
        if(get<1>(a[i])<=maxi) contained[get<2>(a[i])]=1;
        maxi = max(maxi,get<1>(a[i]));
    }
    for(ll i=0; i<n; i++){
        cout << contains[i] << ' ';
    }
    cout << '\n';
    for(ll i=0; i<n; i++){
        cout << contained[i] << ' ';
    }
    cout << '\n';
}

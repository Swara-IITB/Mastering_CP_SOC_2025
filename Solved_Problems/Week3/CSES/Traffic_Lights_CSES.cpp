#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll x,n;
    cin >> x >> n;
    set<ll> p={0,x};
    multiset<ll> a={x};
    while(n--){
        ll y;
        cin >> y;

        auto it = p.upper_bound(y);
        ll r = *it;
        ll l = *(--it);
        a.erase(a.find(r-l));
        a.insert(y-l);
        a.insert(r-y);

        p.insert(y);
        cout << *a.rbegin() << '\n';
    }
}

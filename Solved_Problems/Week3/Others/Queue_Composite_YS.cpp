#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll Q, m= 998244353,A=1,B=0;
    deque<pair<ll,ll>> a;
    cin >> Q;
    while(Q--){
        ll q;
        cin >> q;
        if(q==0){
            ll x,y;
            cin >> x >> y;
            a.push_back({x,y});
            A = A*x ; B = B*x+y;
        } else if(q==2){
            ll x;
            cin >> x;
            x =( x*A + B)%m;
            cout << x << '\n';
        } else if(q==1){
            if(!a.empty()) {
                a.pop_front();
                A /= a[0].first;
                B -= a[0].second*A;
            }
        }
    }
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll x, y,z=1;
        cin >> x >> y;
        if(x==y) cout << -1 << '\n';
        else {
            while(z<max(x,y)){z*=2;}
            cout << z-max(x,y) << '\n';
        }

    }
}

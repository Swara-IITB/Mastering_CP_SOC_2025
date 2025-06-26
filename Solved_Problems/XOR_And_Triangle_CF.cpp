#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll x, z, o,y=0;
        bool zdone = false, odone = false;
        cin >> x;
        for(ll i=0; i<30; i++){
            if(!odone){
                if(((1<<i)&x) != 0){
                    odone = true;
                    y = y | 1<<i;
                }
            }
            if(!zdone){
                if(((1<<i)&x) == 0){
                    zdone = true;
                    y = y | 1<<i;
                }
            }
            if( zdone && odone) {
                break;
            }
        }
        if( x > y && x + (x^y) > y && y + (x^y) > x && x+y > (x^y)){
            cout << y << '\n';
        }else cout << -1 << '\n';
    }
}

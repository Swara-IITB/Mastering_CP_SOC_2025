#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll x, r, c, ans;
    for(int i =1; i<=25; i++){
        cin >> x;
        if(x == 1){
            r = ((i-1)/5 + 1);
            c = (((i-1)%5)<0 ? (i-1)%5 + 5 : (i-1)%5 )+1;
            ans = abs(r-3) + abs(c-3);
            break;
        }
    }
    cout << ans<<'\n';
}
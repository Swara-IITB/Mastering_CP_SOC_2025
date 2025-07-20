#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t,ans=0;
    cin >> t;
    while(t){
        if(t%2) ans++;
        t /= 2;
    }
    cout << ans << '\n';
}
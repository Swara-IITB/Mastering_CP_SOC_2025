#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool even(ll num){
    return num%2==0;
}
int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n, x;
        cin >> n >> x;
        if(n==1 && x==0) {
            cout << -1 << '\n';
            continue;
        } else if(n==1){
            cout << x << '\n';
        } else if(x==0){
            if(even(n)) cout << n << '\n';
            else cout << n+3 << '\n';
        } else{
            ll sum=0,ones=0,xp=x;
            while(xp){
                if(!even(xp)) ones++;
                xp/=2;
            }
            if(n <= ones) sum = x;
            else{
                if(even(n-ones)){
                    sum = x + n - ones;
                } else if(ones==1 && !even(x)){
                    sum = x + n - ones + 3;
                } else{
                    sum = x + n - ones + 1;
                }
            }                                                                            
            cout << sum << '\n';
        }
    }
}
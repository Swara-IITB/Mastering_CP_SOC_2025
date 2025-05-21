#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    ll t, y, x, n;
    cin >> t;
    for(ll i = 0; i<t; i++){
        cin >> y >> x;
        n = (y>=x)?((y%2==0)?(y*y - x+1):(y-1)*(y-1)+x):((x%2==1)?(x*x - y+1):(x-1)*(x-1) + y);
        cout << n << "\n";
    }
}
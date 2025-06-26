#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    if(n==1) cout << 1 << '\n';
    else if(n == 2 || n==3) cout << "NO SOLUTION" << '\n';
    else if(n==4){
        cout << "3 1 4 2" << '\n';
    } else{
        for(ll i=n; i>=1; i-=2){
            cout << i << ' ';
        }
        for(ll i=n-1; i>=1; i-=2){
            cout << i << ' ';
        }
        cout << '\n';
    } 
}

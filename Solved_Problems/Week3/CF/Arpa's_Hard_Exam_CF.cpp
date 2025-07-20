#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    if(t==0) cout << 1 << '\n';
    else if(t%4==1) cout << 8 << '\n';
    else if(t%4==2) cout << 4 << '\n';
    else if(t%4==3) cout << 2 << '\n';
    else if(t%4==0) cout << 6 << '\n';
}

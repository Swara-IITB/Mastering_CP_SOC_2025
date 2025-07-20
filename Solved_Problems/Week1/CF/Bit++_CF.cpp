#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll t, x=0;
    string s;
    cin >> t;
    while(t--){
        cin >> s;
        if(s[1] == '+') x++;
        else x--;
    }
    cout << x << '\n';
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n , k, s, p=0;
    cin >> n >> k;
    for(int i=0; i<k; i++){
        cin >> s;
        if(s > 0) p++;
    }
    if(s>0){
    for(int i =k; i<n; i++){
        ll x;
        cin >> x;
        if(x == s) p++;
    }}
    cout << p << '\n';
}
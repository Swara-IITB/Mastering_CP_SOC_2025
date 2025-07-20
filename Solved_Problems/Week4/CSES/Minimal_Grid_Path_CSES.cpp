#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> a(n),b(n);
    for(ll i=0; i<n; i++){
        cin >> a[i];
        cin >> b[i];
    }
    sort(b.begin(),b.end());
    ll x,y;
    if(b.size()%2){
        x = b[(b.size())/2];
        for(ll i=0; i<n; i++){
        if(a[i] == x){
            cout << i+1 << '\n';
            break;
        }
    }
    } else {
        x = b[(b.size())/2];
        y = b[((b.size())/2)-1];
        for(ll i=0; i<n; i++){
        if(a[i] == x || a[i]==y){
            cout << i+1 << '\n';
            break;
        }
    }
    

}
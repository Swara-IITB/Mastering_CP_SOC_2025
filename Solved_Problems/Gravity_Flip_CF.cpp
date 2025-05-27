#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    cin >> n;
    ll arr[n];
    for(ll _=0; _<n; _++){
        cin >> arr[_];
    }
    sort(arr,arr+n);
    for(ll _=0; _<n; _++){
        cout << arr[_] << " ";
    }
}
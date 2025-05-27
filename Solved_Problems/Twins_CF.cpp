#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n, sum=0;
    cin >> n;
    ll arr[n];
    for(ll i=0; i<n; i++){
        cin >> arr[i];
        sum+=arr[i];
    }
    sort(arr,arr+n);
    ll k=1;
    for(ll s=0; s<=sum; k++){
        s+=arr[n-k];
        sum-=arr[n-k];
    }
    cout << k-1 << '\n';
}
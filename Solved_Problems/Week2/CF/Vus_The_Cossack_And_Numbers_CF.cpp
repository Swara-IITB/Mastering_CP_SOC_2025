#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,sum=0;
    cin >> n;
    vector<double> a(n);
    vector<ll> ans(n);
    for(ll i=0; i<n; i++){
        cin >> a[i];
        ans[i] = trunc(a[i]);
        sum += ans[i];        
    }
    if(sum >0){
        for(ll i=0; sum>0; i++){
            if(a[i] < 0 && a[i]-trunc(a[i]) != -0){
                ans[i] -= 1;
                sum--;
            } 
        }
    } else if(sum < 0){
        for(ll i=0; sum<0; i++){
            if(a[i] > 0 && a[i]-trunc(a[i]) != 0){
                ans[i] += 1;
                sum++;
            } 
        }
    }
    for(ll i=0; i<n; i++){
        cout << ans[i] << '\n';
    }
   
}
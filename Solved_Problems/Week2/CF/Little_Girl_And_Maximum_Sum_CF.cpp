#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef map<ll,ll> mll;
typedef set<ll> sll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,q,x,y,sum=0,ans=0;
    cin >> n >> q;
    vll a(n);
    for(ll i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    vll diff(n);// diff[i] = pos[i]-pos[i-1]
    vll pos(n);
    for(ll i=0; i<q; i++){
        cin >> x >> y; x--; y--;
        if(!x) diff[0]++;
        else diff[x]++;
        if(y == n-1) continue;
        else diff[y+1]--;
    }
    for(ll i=0; i<n; i++){
        sum += diff[i];
        pos[i] = sum;
    }
    sort(pos.begin(),pos.end());
    for(ll i=n-1; i>=0; i--){
        if(pos[i]==0 || a[i]==0) break;
        ans += pos[i]*a[i];
    }
    cout << ans << '\n';
}

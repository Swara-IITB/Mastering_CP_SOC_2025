#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll const M = 1e9+7;

ll gcd(ll u, ll v){ 
    if (u==v) return u;
    ll a = max(u,v), b = min(u,v);
    if(!b) return abs(a);
    return gcd(b,a%b);
}
ll lcm(ll u, ll v){
    if (u==v) return u;
    ll b = max(u,v), a = min(u,v);
    if(a==1) return b;
    if(a==0) return 0;
    return b*a/gcd(a,b);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,ans=1,k=0;
    cin >> n;
    vector<bool> visited(n,false);
    vector<ll> p(n);
    for(ll i=0; i<n; i++){
        cin >> p[i];
        p[i]--;
    }
    for(ll i=0; i<n; i++){
        if(k==n) break;
        if(!visited[i]){
            ll cnt=0;
            visited[i]=true;
            k++;cnt++;
            ll x = p[i];
            ll j = x;
            while(j!=i){
                visited[j]=true;
                k++;cnt++;
                j = p[j];
            }
            ans = lcm(ans,cnt);
        }
    }
    cout << ans% M << '\n';
}

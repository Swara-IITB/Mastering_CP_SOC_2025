#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,m,x,y,ans=0;
    cin >> n >> m;
    vector<ll> pos(n), a(n);
    for(ll i =0 ; i< n; i++){
        cin >> a[i];
        pos[a[i]] = i;
    }
    for(ll i=0; i<n-1; i++){
        if(pos[i+1]<pos[i]) ans++;
    }
    while(m--){
        cin >> x >> y;
        x--; y--;
        if(!a[x]){
            if(pos[a[x]-1] > pos[a[x]]) ans--;
        }
        if(a[x] != n-1){
            if(pos[a[x]+1] < pos[a[x]]) ans--;
        }
        if(!a[y]){
            if(pos[a[y]-1] > pos[a[y]]) ans--;
        }
        if(a[y] != n-1){
            if(pos[a[y]+1] < pos[a[y]]) ans--;
        }
        pos[a[x]] = y;
        pos[a[y]] = x;
        swap(a[x],a[y]);
        if(!a[x]){
            if(pos[a[x]-1] > pos[a[x]]) ans--;
        }
        if(a[x] != n-1){
            if(pos[a[x]+1] < pos[a[x]]) ans--;
        }
        if(!a[y]){
            if(pos[a[y]-1] > pos[a[y]]) ans--;
        }
        if(a[y] != n-1){
            if(pos[a[y]+1] < pos[a[y]]) ans--;
        }

        cout << ans << '\n';
    }
}
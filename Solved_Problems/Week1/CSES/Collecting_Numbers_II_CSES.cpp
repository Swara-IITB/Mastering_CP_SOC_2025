#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,m,ans=1;
    cin >> n >> m;
    vector<ll> arr(n);
    vector<ll> pos(n);
    for(ll i=0; i<n; i++){
        cin >> arr[i];
        pos[arr[i]-1] = i;
    }
    for(ll i=0; i<n-1;i++){
        if(pos[i]>pos[i+1]) ans++; 
    }
    while(m--){
        ll x,y;
        cin >> x >> y; x--; y--;
        ll a = min(x,y), b= max(x,y);
        
        
                if(pos[arr[a]+1] < pos[arr[a]]) ans--;
                if(arr[a]!=0){if(pos[arr[a]-1] > pos[arr[a]]) ans--;}
                if(arr[b]!=n-1){if(pos[arr[b]+1] < pos[arr[b]]) ans--;}
                if(pos[arr[b]-1] > pos[arr[b]]) ans--;
                if(pos[arr[a]+1] < pos[arr[b]]) ans++;
                if(arr[a]!=0){if(pos[arr[a]-1] > pos[arr[b]]) ans++;}
                if(arr[b]!=n-1){if(pos[arr[b]+1] < pos[arr[a]]) ans++;}
                if(pos[arr[b]-1] > pos[arr[a]]) ans++;
            
        
        cout << ans << '\n';
        swap(arr[a],arr[b]);
        swap(pos[arr[a]],pos[arr[b]]);
    }
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n, k=0,x, ans=0;
    cin >> n;
    while(n--){
        for(int i=0;i<3;i++){
            cin >> x;
            if(x == 1) k++;
        }
        if (k>=2) ans++;
        k = 0;
    }
    cout << ans << '\n';
}
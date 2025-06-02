#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
       ll n,c=0;
       cin >> n;
       while(n > 0){
        if(n==4){
            c+=3;
            break;
        }else if(n%2){
            c++;
            n--;
        } else if((n/2)%2){
            c += n/2;
            n /=2;
        } else {
            c++;
            n--;
        }
        if(n==4){
            c++;
            break;
        }else if(n%2){
            n--;
        } else if((n/2)%2){
            n /=2;
        } else {
            n--;
        }
       }
       cout << c << '\n';
    }
}

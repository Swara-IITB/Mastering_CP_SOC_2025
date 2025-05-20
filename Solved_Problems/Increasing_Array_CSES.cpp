#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n, n1, n2, ans = 0;
    cin >> n;
    cin >> n2;
    for(long long i = 0; i<n-1;i++){
        cin >> n1;
        if(n2>n1){
            ans += (n2-n1);
        } else n2 = n1;
        
    }
    cout << ans;
}
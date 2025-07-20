#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n, sum, x;
    cin >> n;
    sum = n*(n+1)/2;
    for(int i=0; i<n-1; i++){
        cin >> x;
        sum -= x;
    }
    cout << sum;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,x;
    cin >> n;
    set<int> a;
    cin >> x;
    a.insert(x);
    for(int i=0; i<n-1; i++){
        cin>>x;
        if(a.count(x-1)){
            a.erase(x-1);
            a.insert(x);
        } else{
            a.insert(x);
        }
    }
    x=a.size();
    cout<< x<<'\n';
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll const VALMAX = 20;//depends on the question
vector<ll> mobius(VALMAX,1);
void start(){
    for(ll i=2; i<VALMAX; i++){
        if(mobius[i]){
            mobius[i] = -mobius[i];
            for(ll j = 2*i; j<VALMAX; j+=i){
                mobius[j] += mobius[i];
            }
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    start();
}
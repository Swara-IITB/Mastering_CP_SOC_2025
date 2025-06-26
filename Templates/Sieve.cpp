#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6+5;
vector<ll> primes;
void sieve(ll N){
    vector<bool> isprime(N,true);
    isprime[0]=isprime[1]=false;
    for(ll i=2; i<N; i++){
        if(isprime[i]){ 
            primes.push_back(i);
            for(ll j = i*i; j<N; j+=i){
                isprime[j]=false;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    sieve(N);
}

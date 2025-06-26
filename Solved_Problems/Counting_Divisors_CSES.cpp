#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll const N = 1e6+5;
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
    ll t;
    map<ll,ll> a;
    cin >> t;
    while(t--){
        ll n,ans=1;
        cin >> n;
        if(a[n]) cout << a[n] << '\n';
        else {
            ll p = n;
            for(auto x : primes){
                if(x*x > p) break;
                ll k=1;
                while(n%x==0){
                    n/=x;
                    k++;
                }
                ans *= k;
                if(n==1) break;
            }
            if(n>1) ans *= 2;
            a[p] = ans;
            cout << ans << '\n';
        }
    }
}

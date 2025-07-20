#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        long long ans = 0;
        vector<bool> is_prime(n,true);
        is_prime[0]=is_prime[1]=false;
        for(long long i=2; i<n; i++){
            if(is_prime[i]){
                ans++;
                if(i*i<n){
                    for(long long j=i*i; j<n; j+=i){
                        is_prime[j]=false;
                    }
                }
            }
        }
        return ans;
    }
};
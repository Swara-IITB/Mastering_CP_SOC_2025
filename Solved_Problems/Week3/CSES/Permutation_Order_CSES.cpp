#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 21;

ll fact[N];

void precompute(){
    fact[0] = 1;
    for(ll i = 1; i < N; ++i){
        fact[i] = (fact[i-1] * i) ;
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    precompute();
    ll t;
    cin >> t;
    while(t--){
        ll q;
        cin >> q;
        if(q==1){
            ll n,k;
            cin >> n >> k;
            vector<ll> nums;
            for(ll i=1; i<=n; i++) nums.push_back(i);
            k--;
            for(ll i=n; i>=1; i--){
                ll idx = k/fact[i-1];
                cout << nums[idx] << ' ';
                nums.erase(nums.begin()+idx);
                k %= fact[i-1];
            }
            cout << '\n';
        } else if(q==2){
            ll n,k=1;
            cin >> n;
            vector<ll> nums;
            for(ll i=1; i<=n; i++) nums.push_back(i);
            for(ll i=1; i<=n; i++){
                ll x;
                cin >> x;
                ll idx = find(nums.begin(),nums.end(),x) - nums.begin();
                k += idx*fact[n-i];
                nums.erase(nums.begin()+idx);
            }
            cout << k << '\n';
        }
    }
}

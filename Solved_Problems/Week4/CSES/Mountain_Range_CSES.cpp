#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef map<ll,ll> mll;
typedef set<ll> sll;
#define ain(a,n) for(ll lambda=0; lambda<n; lambda++){cin >> a[lambda];}
#define aout(a,n) for(ll _=0; _<n; _++){cout << a[_] << ' '}
#define F first
#define S second 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    vll a(n);
    ain(a,n);
    ll answer = 1;
    stack<pair<ll,ll>> st;
    st.push({a[0],1});
    for(ll i=1; i<n; i++){
        ll res = -1;
        while(!st.empty() && st.top().F<a[i]){
            res = max(res,st.top().S);
            st.pop();
        }
        if(res>0){
            if( st.empty() || st.top().F>a[i]){
                answer = max(answer,res+1);
                st.push({a[i],res+1});
            } else{
                res = max(st.top().S,res);
                answer = max(answer,res);
                st.pop();
                st.push({a[i],res});
            }
        } else if(st.top().F>a[i]){
            ll s = st.size();
            answer = max(answer,s+1);
            st.push({a[i],s+1});
        }
    }
    cout << answer << endl;
}

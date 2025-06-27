#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Returns the k-th smallest element (1-based index)
ll QuickSelect(vector<ll> v, ll k) {
    if (v.empty()) return -1; // Or throw an exception
    ll pivot = v[(rand() % v.size())];
    
    vector<ll> left, right, equal;
    
    for (ll num : v) {
        if (num < pivot) left.push_back(num);
        else if (num > pivot) right.push_back(num);
        else equal.push_back(num);
    }
    
    if (k <= left.size()) {
        return QuickSelect(left, k);
    } else if (k <= left.size() + equal.size()) {
        return pivot;
    } else {
        return QuickSelect(right, k - left.size() - equal.size());
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
}

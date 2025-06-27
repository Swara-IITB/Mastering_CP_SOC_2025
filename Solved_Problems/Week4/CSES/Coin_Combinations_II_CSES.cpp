#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vector<ll> dp(x + 1, 0);
    dp[0] = 1; 

    for (int c : coins) {
        for (int i = c; i <= x; i++) {
            dp[i] = (dp[i] + dp[i - c]) % M;
        }
    }

    cout << dp[x] << '\n';
}

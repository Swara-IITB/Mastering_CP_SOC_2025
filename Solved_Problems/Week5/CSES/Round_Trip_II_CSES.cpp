#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 1e5+5;
vector<ll> adj[N];
bool visited[N], inStack[N];
ll parent[N];
ll n, m;
ll startOfCycle = -1;

bool dfs(ll u) {
    visited[u] = true;
    inStack[u] = true;

    for (ll v : adj[u]) {
        if (!visited[v]) {
            parent[v] = u;
            if (dfs(v)) return true;
        } else if (inStack[v]) {
            parent[v] = u;
            startOfCycle = v;
            return true;
        }
    }

    inStack[u] = false;
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (ll i = 0; i < m; i++) {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    for (ll i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(i)) {
                vector<ll> cycle;
                ll cur = parent[startOfCycle];
                cycle.push_back(startOfCycle);
                while (cur != startOfCycle) {
                    cycle.push_back(cur);
                    cur = parent[cur];
                }
                cycle.push_back(startOfCycle);
                reverse(cycle.begin(), cycle.end());

                cout << cycle.size() << '\n';
                for (ll x : cycle) cout << x << ' ';
                cout << '\n';
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
}

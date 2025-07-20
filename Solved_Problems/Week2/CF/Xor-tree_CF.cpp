#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<ll>> adj;
vector<ll> lvl, cur, goal, a;
vector<bool> visited, frozen;

void dfs(ll node, ll depth) {
    if (visited[node]) return;
    visited[node] = true;
    lvl[node] = depth;
    for (auto u : adj[node]) {
        dfs(u, depth + 1);
    }
}

void xortree(ll node, ll L) {
    for (auto p : adj[node]) {
        if (lvl[p] > lvl[node] && (lvl[p] - L) % 2 == 0)
            cur[p] ^= 1;
        if (lvl[p] > lvl[node])
            xortree(p, L);
    }
}

void tree(ll node, ll& ans) {
    if (frozen[node]) return;
    if (cur[node] == goal[node]) {
        frozen[node] = true;
        for (auto u : adj[node]) {
            tree(u, ans);
        }
    } else {
        ans++;
        a.push_back(node + 1); // +1 for 1-based output
        cur[node] ^= 1;
        frozen[node] = true;
        xortree(node, lvl[node]);
        for (auto u : adj[node]) {
            tree(u, ans);
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    ll n_nodes, x, y, ans = 0;
    cin >> n_nodes;

    adj.resize(n_nodes);
    lvl.resize(n_nodes);
    visited.assign(n_nodes, false);
    frozen.assign(n_nodes, false);
    cur.resize(n_nodes);
    goal.resize(n_nodes);

    for (ll i = 0; i < n_nodes - 1; i++) {
        cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }

    dfs(0, 1); // root at 0, level starts from 1

    for (ll i = 0; i < n_nodes; i++) cin >> cur[i];
    for (ll i = 0; i < n_nodes; i++) cin >> goal[i];

    tree(0, ans);

    cout << ans << '\n';
    for (auto u : a) {
        cout << u << '\n';
    }
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll const N = 10; //adjust based on problem
vector<ll> adj[N];
bool visited[N];

void dfs(ll starting_node){
    if(visited[starting_node]) return;
    visited[starting_node] = true;
    //process starting_node
    for(auto u : adj[starting_node]){
        dfs(u);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    
    ll n_nodes, n_edges,x,y;
    cin >> n_nodes >> n_edges;
    for (ll i = 0; i < n_edges; i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x); // remove if directed graph
    }


}

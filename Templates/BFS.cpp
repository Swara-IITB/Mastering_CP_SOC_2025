#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll const N = 10; //adjust based on problem
queue<ll> q;
vector<ll> adj[N];
bool visited[N];
ll dist[N];

void bfs(ll starting_node){
    q.push(starting_node);
    visited[starting_node] = true;
    dist[starting_node]=0;
    while(!q.empty()){
        ll s = q.front();
        q.pop();
        //process s
        for(auto u :adj[s]){
            if(visited[u]) continue;
            visited[u] = true;
            q.push(u);
            dist[u] = dist[s]+1;
        }
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

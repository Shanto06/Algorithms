#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
vector < int > g[maxn];
bool visit[maxn];

void dfs(int src){
    if(visit[src] == true)return;
    visit[src] = true;
    cout << src << " ";
    for(auto v : g[src])dfs(v);

//    for(int i = 0; i<g[src].size(); i++){
//        int v = g[src][i];
//        dfs(v);
//    }
}

int main()
{
    int n , e;
    cout<<"Enter the node and edge: ";
    cin >> n >> e;
    for(int i = 1; i<=e; i++){
        int u , v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int src;
    cout<<"Enter the src: ";
    cin >> src;
    dfs(src);
    return 0;
}

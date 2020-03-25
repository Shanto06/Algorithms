#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e4;
vector < int > g[maxn];
bool visit[maxn];

void dfs(int u){
    if(visit[u] == true)return;
    visit[u] = true;
    for(auto v : g[u])dfs(v);
}

int main()
{
    int n , e;
    cin >> n >> e;
    for(int i = 1; i<=e; i++){
        int u , v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int cmp = 0;
    for(int i = 1; i<=n; i++){
        if(visit[i] == false){
            cmp++;
            dfs(i);
        }
    }
    cout << cmp << endl;
}

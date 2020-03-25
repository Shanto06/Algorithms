#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
vector < int > g[maxn];
stack<int>tpsort;
bool visit[maxn];

void topSort(int u){
    if(visit[u] == true)return;
    visit[u] = true;
    for(auto v : g[u])topSort(v);
    tpsort.push(u);
}

int main()
{
    int n , e;
    cin >> n >> e;
    for(int i = 1; i<=e; i++){
        int u , v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    for(int i = 1; i<=n; i++){
        if(visit[i] == false)topSort(i);
    }
    while(!tpsort.empty()){
        cout << tpsort.top() << " ";
        tpsort.pop();
    }
    return 0;
}

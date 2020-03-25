#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 100;
int n, parent[maxn];
vector < pair < int , pair < int  , int > > > edges;

int getRoot(int u){
    if(parent[u] == u)return u;
    else return parent[u] = getRoot(parent[u]);
}

void Union(int u , int v){
    parent[v] = u;
}


int main()
{
    int n , m;
    cin >> n >> m;
    for(int i = 1; i<=m; i++){
        int u , v , w;
        cin >> u >> v >> w;
        edges.push_back(make_pair(w , make_pair(u,v)));
    }
    sort(edges.begin(),edges.end());
    vector < pair < int , pair < int , int > > > MST;
    for(int i = 1; i<=n; i++){
        parent[i] = i;
    }
    for(auto v : edges){
        int uu = v.second.first ,  vv = v.second.second;
        uu = getRoot(uu); vv = getRoot(vv);
        if(uu == vv)continue;
        Union(uu,vv);
        MST.push_back(v);
    }
    for(auto v : MST){
        cout << v.second.first << " <-----> " << v.second.second << " cost " << v.first << endl;
    }
    return 0;
}

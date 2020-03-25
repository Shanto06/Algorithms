#include<bits/stdc++.h>
#include<queue>

using namespace std;

#define WHITE 1
#define GRAY 2
#define BLACK 3

int adj[100][100],color[100],parent[100],dis[1000];
int node,edge,n1,n2,temp;

void BFS(int startingnode)
{
    for(int i=0;i<node;++i)
    {
        color[i]=WHITE;
        dis[i]=INT_MIN;
        parent[i]=-1;
    }

    dis[startingnode]=0;
    parent[startingnode]=-1;

    queue<int>q;
    q.push(startingnode);

    while(!q.empty())
    {
        int x;
        x=q.front();
        q.pop();
        color[x]=GRAY;
        cout<<x<<" ";
        for(int i=0;i<node;++i)
        {
            if(adj[x][i]==1)
            {
                if(color[i]==WHITE)
                {
                    dis[i]=dis[x]+1;
                    parent[i]=x;
                    q.push(i);
                }
            }
        }
        color[x]=BLACK;
    }

}

int main()
{
    cout<<"Enter the number of node: "<<endl;
    cin>>node;
    cout<<"Enter the number of edge: "<<endl;
    cin>>edge;

    for(int i=0;i<edge;++i)
    {
        cin>>n1>>n2;
        adj[n1][n2]=1;
        adj[n2][n1]=1;

    }
    cout<<"enter the starting node: "<<endl;
    cin>>temp;

    BFS(temp);

    return 0;
}

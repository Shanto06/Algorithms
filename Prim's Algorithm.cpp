
#include <bits/stdc++.h>
using namespace std;

int V;
int graph[1000][1000] , key[1000];
bool mstSet[1000] ;int parent[1000];

int minKey()
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}

void printMST()
{
	cout<<"Edge \tWeight\n";
	for (int i = 1; i < V; i++)
		cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";
}

void primMST()
{

	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false;
	key[0] = 0;
	parent[0] = -1;

	for (int count = 0; count < V - 1; count++)
	{

		int u = minKey();

		mstSet[u] = true;

		for (int v = 0; v < V; v++)

			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}

	printMST();
}

int main()
{
	int m;
	cin >> V >> m;
    for(int i = 1; i<=m; i++){
        int u , v , w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }

	primMST();

	return 0;
}

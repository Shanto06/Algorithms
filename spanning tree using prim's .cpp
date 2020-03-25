#include <bits/stdc++.h>
using namespace std;

int V;
int graph[1000][1000] , key[1000];
bool mstSet[1000] ;int parent[1000];
int sum=0;
int cost[1000][1000];



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
	for (int i = 1; i < V; i++){
		cost[i][parent[i]] = graph[i][parent[i]];
		cost[parent[i]][i] = cost[i][parent[i]];
	}
}

void kustMST()
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
	cout<<"Enter the vertices: "<<endl;
	cin >> V ;
	cout<<"Enter the adjacency matrix: ";
	for(int i = 0; i<V; i++){
        for(int j = 0; j<V; j++){
            cin >> graph[i][j];
        }
	}
	kustMST();
	cout << endl;
    for(int i = 0; i<V; i++){
        for(int j = 0; j<V; j++){
            sum+=cost[i][j];
        }
        cout << endl;
    }
    cout<<"total cost of MST: "<<endl;
    cout<<sum/2;
    cout<<endl;
	return 0;
}


//0 3 1 4 0 0
//3 0 0 5 3 0
//1 0 0 5 0 3
//4 5 5 0 0 6
//0 3 0 0 0 2
//0 0 3 6 2 0

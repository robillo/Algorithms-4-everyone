#include <iostream>
#include <time.h>
#include <list>

#define N 6
#define M 8
using namespace std;

void initialize();
int find_representative(int node);
void union_trees(int a, int b);
bool same(int a, int b);

struct Node
{
	int first;			// The graph isn't oriented, so exists the edge first -> second, but exists also the edge second -> first
	int second;
	int weight;

	bool operator<(const Node &rsh)const
	{
		return weight < rsh.weight;
	}
};

Node nodes[M];
int dad[N+1];
int size[N+1];

list<int> spanningTree;

int main()
{

	// creating the graph

	nodes[0].first = 1;
	nodes[0].second = 2;
	nodes[0].weight = 3;

	nodes[1].first = 2;
	nodes[1].second = 3;
	nodes[1].weight = 5;

	nodes[2].first = 3;
	nodes[2].second = 4;
	nodes[2].weight = 9;

	nodes[3].first = 4;
	nodes[3].second = 6;
	nodes[3].weight = 7;

	nodes[4].first = 5;
	nodes[4].second = 6;
	nodes[4].weight = 2;

	nodes[5].first = 1;
	nodes[5].second = 5;
	nodes[5].weight = 5;

	nodes[6].first = 2;
	nodes[6].second = 5;
	nodes[6].weight = 6;

	nodes[7].first = 3;
	nodes[7].second = 6;
	nodes[7].weight = 3;

	sort(nodes, nodes + M);

	for(int i = 0; i < M; i++)
		cout << nodes[i].first << " " << nodes[i].second << " " << nodes[i].weight << endl;

	// Now we create the Spanning Tree
	initialize();
	for(int i = 0; i < M; i++)
	{
		if(!same(nodes[i].first, nodes[i].second))
			union_trees(nodes[i].first, nodes[i].second);
	}

}


void initialize()
{
	for(int i = 1; i <= N; i++)
		size[i] = 1;
	for(int i = 1; i <= N; i++)
		dad[i] = i;							
}

int find_representative(int node)
{
	while(node != dad[node])
		node = dad[node];
	return node;
}

void union_trees(int a, int b)
{		
	cout << "Union of node " << a << " and node " << b << endl;
	a = find_representative(a);
	b = find_representative(b);

	if(size[a] < size[b])
	{
		int temp = size[a];
		size[a] = size[b];
		size[b] = temp;
	}

	// Now size[a] >= size[b]

	size[a] += size[b];
	dad[b] = a;
}

bool same(int a, int b)
{
	return find_representative(a) == find_representative(b);
}


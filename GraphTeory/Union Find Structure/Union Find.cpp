#include <iostream>
#define N 10
using namespace std;

int size[N];					// It contains the size of the subtree under the node i (i is included)
int dad[N];						// It contains the next element in the chain or the element itself if it is a root

void initialize();
int find_representative(int node);
void union_trees(int a, int b);
bool same(int a, int b);

int main() 
{
	initialize();		// When I initialize the tree, each node is in a different tree with size 1
	union_trees(3,4);
	
	cout << "Are 5 and 8 in the same tree?" << " ";
	if(same(5,8))
		cout << "Yes! c:" << endl;
	else
		cout << "No :(" << endl;
	
	union_trees(4,6);
	union_trees(6,8);
	union_trees(3,6);
	union_trees(5,9);
	
	cout << "Are 5 and 8 in the same tree?" << " ";
	if(same(5,8))
		cout << "Yes! c:" << endl;
	else
		cout << "No :(" << endl;
	
	union_trees(8,9);
	
	cout << "Are 5 and 8 in the same tree?" << " ";
	if(same(5,8))
		cout << "Yes! c:" << endl;
	else
		cout << "No :(" << endl;

	cout << "Who is the representative of node 6? " << find_representative(6) << endl;

	union_trees(8,9);

}

void initialize()
{
	for(int i = 0; i < N; i++)
		size[i] = 1;
	for(int i = 0; i < N; i++)
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
	if(same(a,b))
	{
		cout << "Sorry, nodes " << a << " and " << b << 
		" have the same representative, so they are already connected :c " << endl;
		return;
	}
		
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


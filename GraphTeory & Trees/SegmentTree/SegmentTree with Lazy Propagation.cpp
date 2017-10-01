#include <iostream>
#include <time.h>
#define N 6
#define infinity 100100100

using namespace std;

void constructTree(int input[], int segmentTree[], int low, int high, int position);
int query(int lazy[], int segmentTree[], int tree_low, int tree_high, int query_low, int query_high, int position);
void update(int lazy[], int segmentTree[], int tree_low, int tree_high, int query_low, int query_high, int position, int delta);

int main()
{
	srand(time(NULL));			// random
	int input[N]; 					// Our rangetree will answer the queries on this array 
	int segmentTree[4*N]; 		// This is the array that will represent the tree
	int lazy[4*N];
	fill(segmentTree, segmentTree + 4*N, 0);
	fill(lazy, lazy + 4*N, 0);

	for(int i = 0; i < N; i++)
		input[i] = rand()%100; // fill the array with random stuff

	for(int i = 0; i < N; i++)
		cout << input[i] << endl;

	constructTree(input, segmentTree, 0, N, 0);
	cout << "MAX [2,5]: " << query(lazy, segmentTree, 0, N, 2, 5, 0) << endl; 	//What is the biggest number in [2,5]?	
	update(lazy, segmentTree, 0, N, 0, 3, 0,10);											// Update [0,3]
	cout << "MAX [2,5]: " << query(lazy, segmentTree, 0, N, 2, 5, 0) << endl; 	//What is the biggest number in [2,5]?
}

void constructTree(int input[], int segmentTree[], int low, int high, int position)
{
	if(high == low)	//if high == low these is a leaf, so this position is occupied by input[low]
	{
		segmentTree[position] = input[low];
		return;
	}

	int mid = (low + high)/2;

	constructTree(input, segmentTree, low, mid, position*2+1); //first child is at pos*2+1
	constructTree(input, segmentTree, mid + 1, high, position*2+2); //second child is at pos*2+2

	//At this position there will be max(first child, second child)

	segmentTree[position] = max(segmentTree[position*2+1], segmentTree[position*2+2]);
}

int query(int lazy[], int segmentTree[], int tree_low, int tree_high, int query_low, int query_high, int position)
{

	if(lazy[position] != 0)
	{
		segmentTree[position] += lazy[position];
		if(tree_high != tree_low)	//if it isn't a leaf
		{
			lazy[position*2+1] += lazy[position];
			lazy[position*2+2] += lazy[position];
		}
		lazy[position] = 0;
	}

	//	total overlap 
	// return value at this position

	if( query_low <= tree_low && tree_high <= query_high )
		return segmentTree[position];

	// no overlap
	// return a small number

	if(query_low > tree_high || query_high < tree_low)
		return -infinity;	

	// partial overlap
	// we made same query at the children

	int mid = (tree_low + tree_high)/2;
	return max(query(lazy,segmentTree, tree_low, mid, query_low, query_high, position * 2 + 1), 
		query(lazy,segmentTree, mid + 1, tree_high, query_low, query_high, position * 2 + 2));

}

void update(int lazy[], int segmentTree[], int tree_low, int tree_high, int query_low, int query_high, int position, int delta)
{
	if(tree_low > tree_high)
		return;

	if(lazy[position] != 0)
	{
		segmentTree[position] += lazy[position];
		if(tree_high != tree_low)	//if it isn't a leaf
		{
			lazy[position*2+1] += lazy[position];
			lazy[position*2+2] += lazy[position];
		}
		lazy[position] = 0;
	}

	// no overlap

	if(query_low > tree_high || query_high < tree_low)
		return;

	// total overlap

	if( query_low <= tree_low && tree_high <= query_high )
	{
		segmentTree[position] += delta;
		
		if(tree_high != tree_low)	//if it isn't a leaf
		{
			lazy[position*2+1] += delta;
			lazy[position*2+2] += delta;
		}
		return;
	}

	// partial overlap

	int mid = (tree_high + tree_low)/2;
	update(lazy, segmentTree, tree_low, mid, query_low, query_high, position*2+1, delta);
	update(lazy, segmentTree, mid + 1, tree_high, query_low, query_high, position*2+2, delta);

	segmentTree[position] = max(segmentTree[position*2+1], segmentTree[position*2+2]);

}



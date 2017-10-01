#include <iostream>
#include <time.h>
#define N 30
#define infinity 100100100

using namespace std;

void constructTree(int input[], int segmentTree[], int low, int high, int position);
int query(int segmentTree[], int tree_low, int tree_high, int query_low, int query_high, int position);

int main()
{
	srand(time(NULL));		// random
	int input[N]; 				// Our rangetree will answer the queries on this array 
	int segmentTree[4*N]; 		// This is the array that will represent the tree

	for(int i = 0; i < N; i++)
		input[i] = rand()%100; // fill the array with random stuff

	for(int i = 0; i < N; i++)
		cout << input[i] << endl;

	constructTree(input, segmentTree, 0, N, 0);
	cout << "MAX [2,5]: " << query(segmentTree, 0, N, 2, 5, 0) << endl; //What is the biggest number in [2,5]?	
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

int query(int segmentTree[], int tree_low, int tree_high, int query_low, int query_high, int position)
{
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
	return max(query(segmentTree, tree_low, mid, query_low, query_high, position * 2 + 1), 
		query(segmentTree, mid + 1, tree_high, query_low, query_high, position * 2 + 2));

}


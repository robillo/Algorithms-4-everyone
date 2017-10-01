#include <iostream>
#include <list>
#include <stack>
#define N 6
using namespace std;

list<int> normalGraph[N+1];
list<int> reverseGraph[N+1];
list<int> components[N];
stack<int> Stack;
bool visited[N+1];

void recursive(int node)
{
	//cout << node << endl;
	visited[node] = 1;
	for(auto i: normalGraph[node])
		if(!visited[i])
			recursive(i);
	
	Stack.push(node);
}

int main()
{

	// Graph:
	// 1 -> 2 -> 3 -> 1 -> 4 -> 5 -> 6 -> 4 
	// Six nodes, seven edges

	normalGraph[1].push_back(2);
	normalGraph[2].push_back(3);
	normalGraph[3].push_back(1);
	normalGraph[1].push_back(4);
	normalGraph[4].push_back(5);
	normalGraph[5].push_back(6);
	normalGraph[6].push_back(4);

	reverseGraph[2].push_back(1);
	reverseGraph[3].push_back(2);
	reverseGraph[1].push_back(3);
	reverseGraph[4].push_back(1);
	reverseGraph[5].push_back(4);
	reverseGraph[6].push_back(5);
	reverseGraph[4].push_back(6);

	// Now we have to fill the Stack, we use a recursive function to do it

	recursive(1);

	// Now using our Stack, we can find different components: we use the top of the Stack, 
	// if we have visited it we don't do anything, otherwise we count it as the first node of
	// our connected component, then we push all the edges near our actual node in the component (we use
	// the reverse graph to do this). When all the edges have been pushed, we increment the number of 
	//	the components and we restart. 

	int numberOfComponents = 0;
	fill(visited, visited + N + 1, 0);

	while(!Stack.empty())
	{
		int actual = Stack.top();
		Stack.pop();
		if(visited[actual])
			continue;
		components[numberOfComponents].push_back(actual);
		visited[actual] = 1;
		stack<int> temp;
		temp.push(actual);
		while(!temp.empty())
		{
			int actual2 = temp.top();
			temp.pop();
			for(auto j: reverseGraph[actual2])
			{
				if(!visited[j])
				{
					visited[j] = 1;
					components[numberOfComponents].push_back(j);
					temp.push(j);
				}
			}
		}

		numberOfComponents++;
	} 


	for(int i = 0; i < numberOfComponents; i++)
	{
		cout << "Component n. " << i+1 << endl;
		for(auto j: components[i])
			cout << j << " ";
		cout << endl;
	}

}
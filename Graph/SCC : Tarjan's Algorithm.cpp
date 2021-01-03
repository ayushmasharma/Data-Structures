/* 

A directed graph is strongly connected if there is a directed path from any vertex to every other vertex.
A strongly connected component (SCC) of a directed graph is a maximal strongly connected subgraph. 

Tarjan's Algorithm finds the strongly connected components of a DAG in O(V+E) time. This algorithm is DFS based.
Kosaraju's algorithm requires 2 DFS traversals and Tarjan's algorithm requires only 1 DFS traversal.

Algorithm :

1. DFS search produces a DFS tree/forest.
2. Strongly Connected Components form subtrees of the DFS tree.
3. If we can find the head of such subtrees, we can print/store all the nodes in that subtree (including head) and that will be one SCC.
4. There is no back edge from one SCC to another (There can be cross edges, but cross edges will not be used while processing the graph).

To find head of a SCC, we calculate disc and low array. 
The low[u] indicates earliest visited vertex (the vertex with minimum discovery time) that can be reached from subtree rooted with u. A node u is head if disc[u] = low[u].

Low value of a node u can change in two cases:

Case1 (Tree Edge): If node v is not visited already, then after DFS of v is complete, then minimum of low[u] and low[v] will be updated to low[u].
low[u] = min(low[u], low[v]);

Case 2 (Back Edge): When child v is already visited, then minimum of low[u] and Disc[v] will be updated to low[u].
low[u] = min(low[u], disc[v]);

To track the subtree rooted at head, we can use a stack (keep pushing node while visiting). When a head node found, pop all nodes from stack till you get head out of stack.

To make sure, we don’t consider cross edges, when we reach a node which is already visited, we should process the visited node only if it is present in stack, else ignore the node.

*/


#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define vi vector<int>
#define SZ(x) ((int)(x.size()))
#define fi first
#define se second
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define IN(x,y) ((y).find((x))!=(y).end())
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
typedef long long ll;

vi arr[1001];
int vis[1001], in[1001], low[1001];
bool inStack[1001];
stack<int>s;
int timer=1, scc_count=0;

void dfs(int node)
{
	vis[node]=1;                                                               // mark the node as visited
	low[node]=in[node]=timer++;						   // Mark the in and low time of node according to the timer
	inStack[node]=true;							   // We will push the node in stack, so mark the node to be true in inStack
	s.push(node);                                                  		   // Push the node in the stack
	
	for(int i : arr[node])                                         		   // Traversing all the children of the node
	{
		                                                   	       	   // If the node is visited and it is not in the inStack, we will not take the case (as there will be a crossedge)
		if(vis[i]==true && inStack[i]==true)                               // If the node is visited and it is in the inStack, means the children is in the same SCC (It's a backedge) 
			low[node]=min(in[i],low[node]);                            // Case 2 : Back edge (Updating the low time of node)
		else
		{
			if(!vis[i])
			{
				dfs(i);
				if(inStack[i])                                     // If the node was not already visited and it is in the stack, then this is the Tree edge case
				low[node]=min(low[i],low[node]);                   // Case 1 : Tree edge (Updating the low time of node)
			}
		}
	}
	if(low[node]==in[node])                                                    // Case for the head node of the SSC
	{
		scc_count++;
		cout<<"Strongly Connected Component "<<scc_count<<" : "<<endl;
		while(1)
		{
			int temp=s.top();
			s.pop(), inStack[temp]=false;
			cout<<temp<<" ";
			if(temp==node) break;                                     // Popping and printing the elements from the stack until we take the head out of stack
		}
		cout<<endl;
	}
}

int main()
{
	int n,m,a,b;
	cin>>n>>m;                                                  // n is the number of vertices and m is the number of edges
	FORI(i,m)
		cin>>a>>b, arr[a].pb(b);                            // There is an edge fron a to b
	FORI(i,n) vis[i]=false, inStack[i]=false;                   // Clearing the lists for each test case
	FORI(i,n)
		if(!vis[i])
			dfs(i);                                     // Making the DFS call if vertice is not visited
	
}

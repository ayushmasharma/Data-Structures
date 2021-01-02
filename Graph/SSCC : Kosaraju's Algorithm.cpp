/* 

A directed graph is strongly connected if there is a directed path from any vertex to every other vertex.
A strongly connected component (SCC) of a directed graph is a maximal strongly connected subgraph. 

Kosaraju's Algorithm finds the strongly connected components of a DAG in O(V+E) time. This algorithm is DFS based. It does DFS two times.

Algorithm :

Step 1 : First time DFS 
         Create an empty stack ‘S’ and do DFS traversal of a graph. In DFS traversal, after calling recursive DFS for adjacent vertices of a vertex, push the vertex to stack.
Step 2 : Reversal (Transpose Graph)
         Reverse directions of all arcs to obtain the transpose graph.
Step 3 : Second time DFS 
         One by one pop a vertex from S while S is not empty. Let the popped vertex be ‘v’. 
	 Take v as source and do DFS. The DFS starting from v prints strongly connected component of v.
         
We do a DFS of graph and store vertices according to their finish times (out time), 
Since, the out time of a vertex that connects to other SCCs (other that its own SCC), will always be greater than out time of vertices in the other SCC.
In the reversed graph, the edges that connect two components are reversed.
So if we do a DFS of the reversed graph using sequence of vertices in stack, we process vertices from sink to source (in reversed graph). 
That is what we wanted to achieve and that is all needed to print SCCs one by one.

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

vi arr[1001], tr[1001];   // arr: original list, tr : transposed list
vi ssc, order;           // ssc :  contains strongly connected components
                         // order : contains the vertices acc to out time
int vis[1001];           // vis : visited array

void dfs1(int node)
{
	vis[node]=1;
	for(int child : arr[node])
		if(!vis[child]) 
			dfs1(child);
	order.pb(node);   // in first dfs run, we are storing the vertices acc to out time
} 

void dfs2(int node)
{
	vis[node]=1;
	for(int child : tr[node])
		if(!vis[child]) 
			dfs2(child);  
	ssc.pb(node);     // in the second dfs run, we are storing the strongly connected components
}


int main()
{
	int t,n,m,a,b;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;    // n is the number of nodes and m is the number of edges
		FORI(i,n) arr[i].clear(), tr[i].clear(), vis[i]=0; // clearing the lists for all test cases
		order.clear(); // clearing the list in which we are storing the vertices
		while(m--)
		{
			cin>>a>>b;     // there is an edge from a to b 
			arr[a].pb(b);  // in the original list
			tr[b].pb(a);   // in the transpose list
		}
		FORI(i,n) 
			if(vis[i]==0) 
				dfs1(i);   // making the first dfs call
				
		FORI(i,n) vis[i]=0; //clearing the visited array because we have to make second dfs call
		
		FORI(i,n) 
			if(vis[order[n-i]]==0) 
			{
				ssc.clear(); //clearing the list containing strongly connected components after every return
				dfs2(order[n-i]);  // making the second dfs call
				cout<<"Connected Components from "<<order[n-i]<<" : "<<endl;
				for(int node : ssc)
				   cout<<node<<" ";  // printing the vertices in ssc
				cout<<endl;
			}
	}
}

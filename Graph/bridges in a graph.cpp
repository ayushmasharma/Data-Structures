/* Finding bridges in a graph using DFS Tree

   There are three kind of edges in a graph :
   1. Back Edge : It is an edge (u, v) such that v is ancestor of node u but not part of DFS tree. Presence of back edge indicates a cycle in directed graph.
   2. Forward Edge : It is an edge (u, v) such that v is descendant but not part of the DFS tree.
   3. Cross Edge :  It is a edge which connects two node such that they do not have any ancestor and a descendant relationship between them. 
   
   If the tree has a back-edge, then that edge can never be the bridge. Reason : It is a backedge, this means this edge is connecting a node to another node other than its parent.
   If we will remove the backedge, it will not increase the number of connected components. 
   
   Now, there will be three cases in finding the bridges. Will discuss them further.
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
int timer=0;
int vis[1001], in[1001], low[1001];   // in (in time array) will contain the time at which we entered a node ( time will be maintained by the timer variable).
                                      // node with lower in time will be the ancestor and node with higher in time will be the descendant
                                      // low (low time array) will contain the lowest ancestor which can be directly reached from a node

void dfs(int node, int parent)
{
	vis[node]=1;
	in[node]=low[node]=timer;
	timer++;
	for(int child: arr[node])
	{
		/*Now there will be three cases : */
		
		
		// Case 1 : If the node (child) in the adjacency list is the parent of that node. In this case, we will continue.
		if(child == parent) continue;
		
		// Case 2 : If the node is already visited, then this means the edge (child - parent)  is a backedge. In this case, we will minimize the low time of descendant.
		// We can't simply minimize it to the intime of child because it is not sure that whether it is its ascendant or not.
		if(vis[child] == 1)
			low[node] = min(low[node], in[child]);
			
		// Case 3 : If the edge is forward edge. We will make a dfs call to the node.
		else
		{
			dfs(child, parent);
			 
			// It would be a bridge if the low time of child is greater than or equal to in time of node. 
			// Because on removing the child, there will be increase in the number of connected components. As it is not connected to any other ancestor other than its parent.
			if(low[child] > in[node]) cout<<node<<" - > "<<child<<" is a bridge."<<endl; 
			
			// If the low time of child is less than the in time of parent, then there wil be no bridge as the child is also connected to any other ancestor other than its parent.
			// In this case, the parent will try to minimize its low time. As it can also reach the minimum its child is reaching.
			low[node] = min(low[node], low[child]);
		}
	}
}

int main()
{
	int n,m,x,y; // n is the number of nodes and m is the number of edges
	cin>>n>>m;
	while(m--)
	{
		cin>>x>>y;
		arr[x].pb(y);
		arr[y].pb(x);
		dfs(1,-1);     //making dfs call to the root node and passing -1(not possible) as its parent.
	}
}

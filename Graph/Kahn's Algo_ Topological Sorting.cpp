/* Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge uv, vertex u comes before v in the ordering. 
   Topological Sorting for a graph is not possible if the graph is not a DAG.
   
   Kahn's Algorithm is used to find the topological sort of a DAG
   
   Steps involved in finding the topological ordering of a DAG:
   
	Step-1: Compute in-degree (number of incoming edges) for each of the vertex present in the DAG and initialize the count of visited nodes as 0.
	
	Step-2: Pick all the vertices with in-degree as 0 and add them into a queue (Enqueue operation)
	
	Step-3: Remove a vertex from the queue (Dequeue operation) and then.
	
		i.   Increment count of visited nodes by 1.
		ii.  Decrease in-degree by 1 for all its neighboring nodes.
		iii. If in-degree of a neighboring nodes is reduced to zero, then add it to the queue.
		
	Step 5: Repeat Step 3 until the queue is empty.
	
	Step 6: If count of visited nodes is not equal to the number of nodes in the graph then the topological sort is not possible for the given graph.
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

vi  arr[10001], res;
int in[10001];

void kahn(int n)
{
	queue<int>q;
	FORI(i,n) 
		if(in[i]==0) 
			q.push(i);
	while(!q.empty())
	{
		int temp=q.front();
		res.pb(temp);
		q.pop();
		for(int child : arr[temp])
		{
			in[child]--;
			if(in[child]==0)
			   q.push(child);
		}
	}
	cout<<"Topological Sort : ";
	for(int node : res)
	cout<<node<<" ";
}

int main()
{
	int n,m;
	cin>>n>>m;                         // n is the number of nodes and m is the number of edges
	while(m--)
	{
		int x,y;
		cin>>x>>y;                    // There is an edge from x to y
		arr[x].pb(y), in[y]++;	      // Increase the indegree of y by 1
	}
	kahn(n);                          // Passing the number of nodes to the kahn algo function
}

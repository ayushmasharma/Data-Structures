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
			dfs2(child);  // in the second dfs run, we are storingthe strongly connected components
	ssc.pb(node);
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
			arr[a].pb(b);   // in the original list
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

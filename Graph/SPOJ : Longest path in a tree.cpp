#include<bits/stdc++.h>
#define loop(i,n) for(int i=1;i<=n;i++)
#define vi vector<int>
using namespace std;
vi arr[10001];
int vis[10001];
int max_dis,max_node;
void dfs(int node, int dis)
{
	vis[node]=1;
	if(dis>max_dis) max_dis=dis, max_node=node;
	for(int child : arr[node]) 
		if(vis[child]==0)
			dfs(child,dis+1);
}
int main()
{
	int n,u,v;
	cin>>n;
	loop(i,n-1) cin>>u>>v, arr[u].push_back(v), arr[v].push_back(u);
	max_dis = -1;
	dfs(1,0);
	loop(i,n) vis[i]=0;
	max_dis = -1;
	dfs(max_node,0);
	cout<<max_dis;
}

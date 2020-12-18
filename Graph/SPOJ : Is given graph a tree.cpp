#include<bits/stdc++.h>
using namespace std;
int vis[10001];
vector<int>arr[10001];
void dfs(int node)
{
	vis[node]=1;
	for(int child : arr[node])
		if(vis[child]==0)
			dfs(child);
}
int main()
{
	int n,m,u,v,countcc=0;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		arr[u].push_back(v);
		arr[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		dfs(i) , countcc++;
	}
	if(countcc==1 && m==n-1)
	printf("YES");
	else
	printf("NO");
}

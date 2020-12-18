#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int>arr[2001];
int vis[2001];
int col[2001];
bool dfs(int node,int c)
{
	vis[node] = 1;
	col[node] = c;
	for(int child: arr[node])
	{
		if(vis[child]==0)
		{
			bool result = dfs(child, c^1);
			if(result==false) 
			return false;
		}
		else
		{
			if(col[node]==col[child]) return false;
		}
	}
	return true;
}
int main()
{
	int t,n,m,u,v;
	cin>>t;
	for(int tc=1;tc<=t;tc++)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			arr[i].clear(), vis[i]=0;
		while(m--)
		{
			cin>>u>>v;
			arr[u].push_back(v);
			arr[v].push_back(u);
		}
		bool flag=true;
		for(int i=1;i<n;i++)
			if(vis[i]==0)
			{
				bool res=dfs(i,0);
				if(res==false)
				flag=false;
			}
		cout<<"Scenario #"<<tc<<":"<<endl;
		
		if(flag==false)
		cout<<"Suspicious bugs found!"<<endl;
		else
		cout<<"No suspicious bugs found!"<<endl;
    }
    return 0;
}

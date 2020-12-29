#include<bits/stdc++.h>
using namespace std;

vector<int>arr[1000001];
int vis[1000001], cc[1000001];
int curr_comp;

void dfs(int node)
{
	vis[node]=1;
	cc[node]=curr_comp;
	for(int child : arr[node])
		if(vis[child]==0) dfs(child);
}

int main()
{
	int t,n,k,x1,x2;
	string s;
	cin>>t;
	while(t--)
	{
		curr_comp=0;
		vector< pair<int,int> >unequal;
		cin>>n>>k;
		for(int i=1;i<=n;i++) vis[i]=0, arr[i].clear();
		for(int i=1;i<=k;i++) 
		{
			cin>>x1>>s>>x2;
			if(s == "=")
				arr[x1].push_back(x2), arr[x2].push_back(x1);
			else
			    unequal.push_back({x1,x2});
		}
		for(int i=1;i<=n;i++)
		{
			if(vis[i]==0) curr_comp++, dfs(i);
		}
		bool flag =true;
		for(int i=0;i<unequal.size();i++)
		{
			x1=unequal[i].first;
			x2=unequal[i].second;
			if(cc[x1] == cc[x2]) 
			{
				flag=false; 
				break;
			}
		}
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}

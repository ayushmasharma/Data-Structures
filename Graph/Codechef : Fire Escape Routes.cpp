#include<bits/stdc++.h>
#define loop(i,n) for(int i=1;i<=n;i++)
#define vi vector<int>
#define mod 1000000007
using namespace std;
int vis[100001];
vi  arr[100001];
int sizecc;
void dfs(int node)
{
	vis[node]=1;
	sizecc++;
	for(int child : arr[node])
		if(vis[child]==0)
			dfs(child);
}
int main()
{
	int n,m,t,x,y;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		loop(i,n) vis[i]=0, arr[i].clear();
		loop(i,m) cin>>x>>y, arr[x].push_back(y), arr[y].push_back(x);
		long long int res=1;
		int countcc=0;
		loop(i,n)
			if(vis[i]==0)
			{
			    sizecc=0;
				dfs(i), countcc++;
				res=(res*sizecc)%mod;
		    }
		cout<<countcc<<" "<<res<<endl;
	}
	return 0;
}

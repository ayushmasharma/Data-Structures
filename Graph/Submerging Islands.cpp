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

vi arr[100001];
int vis[100001], in[100001], low[100001], timer, child_count;
set<int>ap;

void dfs(int node, int parent)
{
	vis[node]=1;
	low[node] = in[node] = timer++;
	int child_count=0;
	for(int child : arr[node])
	{
		if(child==parent) continue;
		if(vis[child]) low[node]=min(low[node],in[child]);
		else
		{
			dfs(child,node);
			child_count++;
			low[node]=min(low[child],low[node]);
			if(in[node]<=low[child] && parent!=-1) ap.insert(node);
		}
	}
	if(parent==-1 && child_count>1) ap.insert(node);
}

int main()
{
	while(1)
	{
		int n,m,u,v;
		cin>>n>>m;
		if(n==0 && m==0) break;
		for(int i=1;i<=n;i++) arr[i].clear(), vis[i]=0;
		ap.clear();
		timer=0;
		while(m--) cin>>u>>v, arr[u].pb(v), arr[v].pb(u);
		for(int i=1;i<=n;i++) 
			if(!vis[i])
				dfs(1,-1);	
		cout<<ap.size()<<endl;
	}
}

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define vi vector<int>
typedef long long ll;

vi arr[100001];
int vis[100001], in[100001], low[100001], timer=0;
bool hasBridge=false;
vector< pair<int,int> >edgeList; 

void dfs(int node, int parent)
{
	vis[node]=1;
	in[node]=low[node]=timer++;
	for(int child : arr[node])
	{
		if(child==parent) continue;
		if(vis[child]) 
		{
			low[node]=min(low[node],in[child]);
			if(in[child] < in[node]) edgeList.pb({node,child});	
		}
		else
		{
			dfs(child,node);
			if(low[child] > in[node])
			{
				hasBridge=true;
				return;
			}
			edgeList.pb({node,child});
			low[node]=min(low[child],low[node]);
		}
	}
}

int main()
{
	int n,m,a,b;
	cin>>n>>m;
	while(m--)
		cin>>a>>b, arr[a].pb(b), arr[b].pb(a);
	dfs(1,-1);
	if(hasBridge) cout<<"0";
	else 
	{
		for(pair<int,int>e : edgeList)
			cout<<e.first<<" "<<e.second<<endl;
	}
}

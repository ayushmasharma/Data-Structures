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
#define DBG cerr << "debug here" << endl;
#define DBGV(vari) cerr << #vari<< " = "<< (vari) <<endl; 
typedef long long ll;

vector<int>arr[1000001];
int vis[1000001], dis[1000001], level[1000001];

void bfs(int node)
{
	vis[node]=1;
	dis[node]=0;
	queue<int>q;
	q.push(node);
	while(!q.empty())
	{
		int temp=q.front();
		q.pop();
		for(int child : arr[temp])
		{
			if(!vis[child])
			{
				vis[child]=1;
				dis[child]=dis[temp]+1;
				q.push(child);
				level[dis[child]]++;	
			}
		}
	}
}

int main()
{
	int n,e,u,v,src,t,m;
	cin>>n>>e;
	FOR(i,e) cin>>u>>v, arr[u].pb(v), arr[v].pb(u);
	cin>>m;
	while(m--)
	{
		cin>>src>>t;
		FOR(i,n) level[i]=0, vis[i]=0;
		bfs(src);
		cout<<level[t]<<endl;
	}
}


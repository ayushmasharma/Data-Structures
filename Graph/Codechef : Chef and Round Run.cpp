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

vi arr[10001], tr[10001];
vi order, ssc;
int vis[10001], taste_level[10001];

void dfs1(int node)
{
	vis[node]=1;
	for(int child : arr[node])
		if(!vis[child])
			dfs1(child);
	order.pb(node);
}
void dfs2(int node)
{
	vis[node]=1;
	for(int child : tr[node])
	if(!vis[child])
		dfs2(child);
	ssc.pb(node);
}
int main()
{
	int t,n,res=0;
	cin>>t;
	while(t--)
	{
		cin>>n;	
		FOR(i,n) arr[i].clear(), tr[i].clear(), vis[i]=0, cin>>taste_level[i];
		FOR(i,n) 
		{
			int u = i;
			int v = (i+taste_level[i]+1)%n;
			arr[u].pb(v);
			tr[v].pb(u);
		}
		FOR(i,n)
			if(!vis[i])
				dfs1(i);
		FOR(i,n) vis[i]=0;
		reverse(order.begin(),order.end());
		for(int i : order)
		{
			if(!vis[i])
			{
				ssc.clear();
				dfs2(i);	
				if(ssc.size()==1 && ssc[0]!=arr[ssc[0][0]]) continue;
				res+=ssc.size();
			} 
		}
		cout<<res<<endl;
	}
}

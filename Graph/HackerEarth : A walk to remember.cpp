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

vi arr[100001], tr[100001];   
vi ssc, order;           
int vis[100001],res[100001]={0};         

void dfs1(int node)
{
	vis[node]=1;
	for(int child : arr[node])
		if(!vis[child]) 
			dfs1(child);
	order.pb(node);   
} 

int dfs2(int node)
{
	vis[node]=1;
	for(int child : tr[node])
		if(!vis[child]) 
			dfs2(child);  
	ssc.pb(node);
	return ssc.size();
}


int main()
{
	int n,m,a,b;
	cin>>n>>m;    
	FORI(i,n) arr[i].clear(), tr[i].clear(), vis[i]=0; 
	order.clear(); 
	while(m--)
	{
		cin>>a>>b;     
		arr[a].pb(b);   
		tr[b].pb(a);   
	}
	FORI(i,n) 
		if(vis[i]==0) 
			dfs1(i);   
			
	FORI(i,n) vis[i]=0; 
	FORI(i,n) 
		if(vis[order[n-i]]==0) 
		{
			ssc.clear(); 
			int size = dfs2(order[n-i]); 
			if(size>1)
			for(int node : ssc)
			   res[node-1]=1;
	        }
       FOR(i,n)
	  cout<<res[i]<<" ";
}

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

vi  arr[10001], res;
int in[10001];

bool kahn(int n)
{
    priority_queue <int, vector<int>, greater<int> > q;   // Creating a min heap for priority queue 
	FORI(i,n) 
		if(in[i]==0) 
			q.push(i);
	while(!q.empty())
	{
		int temp=q.top();
		res.pb(temp);
		q.pop();
		for(int child : arr[temp])
		{
			in[child]--;
			if(in[child]==0)
			   q.push(child);
		}
	}
	return (res.size()==n);
}

int main()
{
	int n,m;
	cin>>n>>m;                        
	while(m--)
	{
		int x,y;
		cin>>x>>y;                   
		arr[x].pb(y), in[y]++;	      
	}
	if (kahn(n)) 
		for(int node : res) cout<<node<<" ";
	else cout<<"Sandro fails.";                          
}

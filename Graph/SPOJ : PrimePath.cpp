#include<bits/stdc++.h>
using namespace std;
vector<int>arr[100001];
vector<int>primes;
int dis[100001], vis[100001];

bool isValid(int a, int b)
{
	int count=0;
	while(a)
	{
		if((a%10) != (b%10)) count++;
		a/=10, b/=10;
	}
	if(count==1) return true;
	else return false; 
}
bool isPrime(int n)
{
	for(int i=2;i*i<=n;i++)
		if(n%i==0) return false;
		else return true;
}
void graph()
{
	for(int i=1000;i<=9999;i++)
	   if(isPrime(i)) primes.push_back(i);
	for(int i=0;i<primes.size();i++)
	    for(int j=i+1;j<primes.size();j++)
	    {
	    	int u=primes[i];
			int v=primes[j];
	    	if(isValid(u,v)) arr[u].push_back(v), arr[v].push_back(u);
		}
}
void bfs(int node)
{
	queue<int>q;
	q.push(node);
	vis[node]=1;
	dis[node]=0;
	while(!q.empty())
	{
		int temp=q.front();
		q.pop();
		for(int child : arr[temp])
			if(vis[child]==0)
			{
				vis[child]=1;
				dis[child]=dis[temp]+1;
				q.push(child);
			}
	}
}
int main()
{
	int t,a,b;
	cin>>t;
	graph();
	while(t--)
	{
		cin>>a>>b;
		for(int i=1000;i<=9999;i++) vis[i]=0, dis[i]=-1;
		bfs(a);
		if(dis[b]==-1) cout<<"Impossible"<<endl;
		else cout<<dis[b]<<endl;
	}
}

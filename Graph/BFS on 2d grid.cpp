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

int n,m;
int vis[10001][10001], dis[10001][10001];

bool isValid(int x, int y)
{
	if(x<0 || x>n || y<0 || y>m) return false;
	if(vis[x][y]==1) return false;
	return true;
}

int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};

void bfs(int x, int y)
{
	queue<pair<int,int> >q;
	q.push({x,y});
	dis[x][y]=0;
	vis[x][y]=1;
	while(!q.empty())
	{
		int currX=q.front().first;
		int currY=q.front().second;
		q.pop();
		for(int i=0;i<4;i++)
		{
			if(isValid(currX + dx[i], currY + dy[i]))
			{
				int newX = currX + dx[i];
				int newY = currY + dy[i];
				q.push({newX,newY});
				vis[newX][newY]=1;
				dis[newX][newY]=dis[currX][currY]+1;
			}
		}
	}
	cout<<"Distance Array : "<<endl;
	FORI(i,n)
	{
		FORI(j,m)
		{
			cout<<dis[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	int x,y;
	cin>>n>>m;   
	cin>>x>>y;   //coordinates of source node
	bfs(x,y);
}

// A knight moves in an “L-shape” i.e. they can move two squares in any direction vertically followed by one square horizontally, or two squares in any direction horizontally followed by one square vertically.


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

int vis[100][101], dis[101][101];
int startX, startY, targetX, targetY;
int dx[]={-2,-1,1,2,2,1,-1,-2};
int dy[]={1,2,2,1,-1,-2,-2,-1};

bool isValid(int i, int j)
{
	if(i<1 || i>8 || j<1 || j>8) return false;
	if(vis[i][j]==1) return false;
	return true;
}
int getX(char a)
{
	return a-'a'+1;
}
int bfs(int x, int y)
{
	queue<pair<int,int> >q;
	q.push({x,y});
	vis[x][y]=1;
	dis[x][y]=0;
	if(x==targetX && y==targetY) return dis[x][y];
	while(!q.empty())
	{
		int currX = q.front().first;
		int currY = q.front().second;
		q.pop();
		FOR(i,8)
		{
			if(isValid(currX + dx[i], currY + dy[i]))
			{
				int newX = currX + dx[i];
				int newY = currY + dy[i];
				q.push({newX,newY});
				vis[newX][newY]=1;
				dis[newX][newY]=dis[currX][currY]+1;
				if(newX==targetX && newY==targetY) return dis[newX][newY];
			}
		}
	}
}
int main()
{
	int t;
	char a,b;
	cin>>t;
	while(t--)
	{
		FORI(i,8) 
			FORI(j,8)
				vis[i][j]=0;
		cin>>a>>b;
		startX = getX(a);
		startY = b - '0';
		cin>>a>>b;
		targetX = getX(a);
		targetY = b - '0';
		cout<<bfs(startX,startY)<<endl;
	}
}

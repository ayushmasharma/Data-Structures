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

char arr[31][31];
int vis[31][31], dis[31][31], n;
int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};

bool isValid(int i, int j)
{
	if(i<1 || i>n || j<1 || j>n) return false;
	if(vis[i][j]==1 || arr[i][j]=='T') return false;
	return true;
}

void bfs(int x, int y)
{
	queue<pair<int,int> >q;
	q.push({x,y});
	dis[x][y]=0;
	vis[x][y]=1;
	
	while(!q.empty())
	{
		int currX = q.front().first;
    	int currY = q.front().second;
	    q.pop();
		for(int i=0;i<4;i++)
		{
			if(isValid(currX + dx[i], currY + dy[i]))
			{
				int newX = currX + dx[i];
				int newY = currY + dy[i];
				q.push({newX, newY});
				vis[newX][newY]=1;
				dis[newX][newY]=dis[currX][currY]+1;
		    }
	    }
	}
}

int main()
{
	int startX,startY,endX,endY;
	cin>>n;
	FORI(i,n) {
		FORI(j,n){
			cin>>arr[i][j];
			if(arr[i][j]=='S') startX=i, startY=j;
			if(arr[i][j]=='E') endX=i, endY=j;
		}
	}
	bfs(startX, startY);		
	cout<<dis[endX][endY]<<endl;
}

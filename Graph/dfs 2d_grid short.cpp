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

int n,m,vis[101][101];

bool isValid(int i, int j)
{
	if(i<1 || i>n || j<1 ||j>m) return false;
	if(vis[i][j]) return false;
	return true;
}

int dx[]={-1,1,0,0}; //up-down-right-left
int dy[]={0,0,1,-1}; //up-down-right-left

void dfs(int x, int y)
{
	vis[x][y]=1;
	cout<<x<<" "<<y<<endl;
	for(int i=0;i<4;i++)
		if(isValid(x+dx[i], y+dy[i])) 
		dfs(x+dx[i], y+dy[i]);
}

int main()
{
	cin>>n>>m;
	dfs(1,1);
}

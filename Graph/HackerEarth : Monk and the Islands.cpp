#include<bits/stdc++.h>
using namespace std;
vector<int>arr[10001];
int vis[10001], dis[10001];

void bfs(int node)
{
    queue<int>q;
    q.push(node);
    vis[node]=1;
    dis[node]=0;
    while(!q.empty())
    {
        for(int child : arr[node])
        {
            int temp=q.front();
            q.pop();
            if(!vis[child])
            {
                vis[child]=1;
                q.push(child);
                dis[child]=dis[node]+1;
            }
        }
    }
}
int main()
{
    int t,n,m,x,y;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            arr[i].clear(), vis[i]=0;
        for(int i=1;i<=m;i++)
            cin>>x>>y, arr[x].push_back(y), arr[y].push_back(x);
        bfs(1);
        cout<<dis[n]<<endl;
    }
}

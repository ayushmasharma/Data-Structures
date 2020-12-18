#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int vis[1000001];
vector<int>arr[1000001];
void dfs(int node)
{
    vis[node]=1;
    for(int child : arr[node])
       if(vis[child]==0)
         dfs(child);
}
int main()
{
    int n,e,u,v;
    cin>>n>>e;
    for(int i=1;i<=e;i++)
    {
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    int countcc=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            dfs(i);
            countcc++;
        }
    }
    cout<<countcc;
}


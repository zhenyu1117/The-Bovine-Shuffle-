#include<bits/stdc++.h>
using namespace std;
int n,to[200005],id[200005],ans=0;
bool inring[200005],useless[200005];
int dfs(int now)
{
    if(inring[now])return 0;
    inring[now]=1;
    return dfs(to[now])+1;
}
void dfs2(int now)
{
    useless[now]=1;
    --id[to[now]];
    if(!id[to[now]])dfs2(to[now]);
}
int main()
{
    int a;
    cin>>n;for(int i=1;i<=n;++i){cin>>a;to[i]=a;++id[a];}
    for(int i=1;i<=n;++i)if(!id[i]&&!useless[i])dfs2(i);
    for(int i=1;i<=n;++i)if(!inring[i]&&!useless[i])ans+=dfs(i);
    cout<<ans<<endl;
    return 0;
}

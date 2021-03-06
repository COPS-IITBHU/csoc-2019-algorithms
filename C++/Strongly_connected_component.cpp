#include<bits/stdc++.h>
#include<iomanip>
#define lld long long int
#define ld long double
#define mod 1000000007
#define all(v) v.begin(),v.end()
#define rep(i,a,b)	for(lld i=a;i<=b;i++)
#define repr(i,a,b) for(lld i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
using namespace std;
vector<lld>     adj[200005],adjrev[200005];
vector<int> visited(200005,0);
vector<lld> order,component;
void dfs1(lld s)
{
    visited[s]=1;
    lld sz=adj[s].size();
    for(lld i=0;i<sz;i++)
    {
        if(visited[adj[s][i]]==0)
            dfs1(adj[s][i]);
    }
    order.pb(s);
}
void dfs2(lld s)
{
    visited[s]=1;
    lld sz=adjrev[s].size();
    component.pb(s);
    for(lld i=0;i<sz;i++)
    {
        if(!visited[adjrev[s][i]])
            dfs2(adjrev[s][i]);
    }
}
int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
      lld x,y,n,m;
      cin>>n>>m;
      rep(i,0,m-1)
      {
          cin>>x>>y;
          adj[x].pb(y);
          adjrev[y].pb(x);
          //adj[y].pb(x);  //if graph is directed delete this line
      }
      // if more than one testcase refresh visited and order
      rep(i,1,n)
      {
          if(!visited[i])
            dfs1(i);
      }
      reverse(all(order));
      visited.assign(n+1,0LL);
      rep(i,0,n-1)
      {
          lld x=order[i];
          if(!visited[x])
          {
              dfs2(x);
              lld sz=component.size();
              rep(j,0,sz-1)
              cout<<component[j]<<" ";
              cout<<endl;
              component.clear();
          }
      }
    return 0;
}

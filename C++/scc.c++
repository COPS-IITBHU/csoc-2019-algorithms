/*
My implementation for kosaraju is [here](https://codeforces.com/contest/427/submission/38634551).
The problem is [here](https://codeforces.com/contest/427/problem/C).
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;
typedef vector<lld> vi;
typedef pair<lld,lld> pi;
#define F first
#define S second
#define PB push_back
#define MOD 1000000007
#define MP make_pair
#define rep(i,a,b) for (lld i = a; i < b; i++)
lld l,x,y,n,m,i,z,p,s,e,q,j,k,g,b,d,t,h,sum=0;string s1,s2;
vi v[100009],rev[100009],v2;lld visited[100009],visited2[100009],visited3[100009],val[100009];
void dfs1(lld s)
{
  visited[s]=1;
  for(auto x:v[s])
  {
    if(visited[x]==0)
    {
      dfs1(x);
    }
  }v2.PB(s);
}
void dfs2(lld s)
{
  visited2[s]=1;
  l=min(l,val[s]);
  for(auto x:rev[s])
  {
    if(visited2[x]==0)
    {
      dfs2(x);
    }
  }
}
void dfs3(lld s,lld l)
{
  visited3[s]=1;
  if(val[s]==l)g++;
  for(auto x:rev[s])
  {
    if(visited3[x]==0)
    {
      dfs3(x,l);
    }
  }
}
lld kosaraju()
{
  rep(i,1,n+1)
  {
    if(!visited[i])
      dfs1(i);
  }
//  for(auto x:v2)
  //  cout<<x<<" ";
  s=0;k=1;//cout<<endl;
  for(i=v2.size()-1;i>=0;i--)
  {
    if(!visited2[v2[i]])
    {
      l=MOD;
      dfs2(v2[i]);
      g=0;
      //cout<<l<<" ";
      s=s+l;
      dfs3(v2[i],l);
      g=g%MOD;
      k=(k*g)%MOD;k=(k+MOD)%MOD;
    }
  }//cout<<endl;
  cout<<s<<" "<<k;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);
  cin>>n;
  rep(i,1,n+1)cin>>val[i];
  cin>>m;
  while(m--)
  {
    cin>>x>>y;
    v[x].PB(y);
    rev[y].PB(x);
  }
  kosaraju();
}

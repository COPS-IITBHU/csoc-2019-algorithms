#include <bits/stdc++.h>
using namespace std;
/* Written by Nishant Mittal aka nishantwrp */
#define FAST std::ios_base::sync_with_stdio(false);
#define modnum 1000000007
#define mp make_pair
#define pb push_back
#define sl(a) (long long int)a.length()
#define sz(a) (long long int)a.size()
#define lcase(a) (char)tolower(a)
#define ucase(a) (char)toupper(a)
#define precise(a) fixed<<setprecision(a)<<
#define F first
#define S second
#define I insert
#define pii pair<long long int,long long int>
#define time cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
#define lldmark cout<<"Long Long long long int ..................................... Long Long long long int\n";
#define invect(data,n,commands) for(long long int i = 0;i<n;i++){long long int tmp;cin>>tmp;data.pb(tmp);commands}
#define inset(data,n,commands) for(long long int i = 0;i<n;i++){long long int tmp;cin>>tmp;data.I(tmp);commands}
#define disvect(data) for(long long int disp = 0;disp<sz(data);disp++){cout<<data[disp]<<" ";}cout<<endl;
#define disset(data) for(pair<set <long long int>::iterator,long long int> disp= mp(data.begin(),0);disp.S<sz(data);disp.F++){cout<<*disp.F<<" ";disp.S++;}cout<<endl;
#define ingrid(data,n,commands) for(long long int i = 0; i<n; i++){cin>>data[i];commands}
#define section(a,b,w) set_long long intersection(a.begin(), a.end(),b.begin(), b.end(),back_inserter(w));
#define union(a,b,w) set_union(a.begin(), a.end(),b.begin(), b.end(),back_inserter(w));
#define copy(a,w) copy(a.begin(), a.end(),back_inserter(w));
#define PI 3.14159265358979323844
#define endl '\n'
vector <long long int> nodes[100005];
vector <long long int> tnodes[100005];
vector <long long int> tovisit;
vector <long long int> sccvisited(100005);
vector <long long int> dfsvisited(100005);
long long int ans = 0;
void scc(long long int node) {
sccvisited[node] = 1;
for (auto i : nodes[node])
  {
    if (!sccvisited[i])
    {
      scc(i);
    }
  }
tovisit.pb(node);
}
long long int minv = -1;
long long int mincnt = 1;
vector <long long int> currscc;
void finaldfs(long long int node) {
  dfsvisited[node] = 1;
  currscc.pb(node);
  for (auto i : tnodes[node]) {
    if (!dfsvisited[i])
    {
      finaldfs(i);
    }
  }
}
int main()
{
FAST
long long int n;
cin>>n;
long long int m;
cin>>m;
for (long long int i = 0; i < m; ++i)
{
  long long int a,b;
  cin>>a>>b;
  nodes[a].pb(b);
  tnodes[b].pb(a);
}
for (long long int i = 1; i <= n; ++i)
{
  if (!sccvisited[i])
  {
    scc(i);
  }
}
vector <vector <long long int>> sccs;
long long int j = sz(tovisit) - 1;
while (j >= 0) {
  if (!dfsvisited[tovisit[j]])
  {
    finaldfs(tovisit[j]);
    sccs.pb(currscc);
    currscc.clear();
  }
  j--;
}
for (auto i : sccs) {
  for (auto j : i) {
    cout<<j<<" ";
  }
  cout<<endl;
}
return 0;
}
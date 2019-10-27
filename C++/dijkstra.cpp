#include<iostream>
#include<queue>

using namespace std;

#define rep(i,m,n) for(ll i = m; i < n; i++)
#define pb push_back
#define mp(x,y) make_pair(x,y)
#define F first
#define S second
#define ll long long
#define N 100001
#define inf 1000000000000000001

class Dijkstra
{
	public:
		vector<pair<ll,ll> > adj[N];
		ll parent[N];
		ll key[N];
		bool inSS[N];

		void begin()
		{
			ll nodes,edges,x,y,w;
			cin>>nodes>>edges;
			rep(i,0,edges)
			{
				cin>>x>>y>>w;
				adj[x].pb(mp(y,w));
				adj[y].pb(mp(x,w));
			}

			rep(i,0,N)
			{
				parent[i]=-1;
				inSS[i]=false;
				key[i]=inf;
			}

			DijkstraAlgo();
			printShortestPath();
		}

		void DijkstraAlgo()
		{
			priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > Q;
			pair<ll,ll> x;
			ll source=0;
			key[source]=0;
			Q.push(mp(key[source],source));
			while(!Q.empty())
			{
				x=Q.top();
				Q.pop();
				inSS[x.S]=true;
				for(auto p:adj[x.S])
				{
					if(!inSS[p.F]&&(p.S+x.F)<key[p.F])
					{
						key[p.F]=p.S+x.F;
						Q.push(mp(key[p.F],p.F));
						parent[p.F]=x.S;
					}
				}
			}
		}

		void printShortestPath()
		{
			rep(i,0,N+1)
			{
				if(inSS[i])
				{
					cout<<"Node::"<<i<<"  Distance from source::"<<key[i]<<endl;
				}
			}
		}
};

int main()
{
	Dijkstra d;
	d.begin();
	return 0;
}

#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define lli long long int
#define F first
#define S second
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAX1 998244353
#define MAX2 1000000007
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    std::cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');std::cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}

//Written By Mudit Bhardwaj aka GHATAK...
/*--------------------------------------------------------------------*/
//vector<pair<lli,lli>>adj[300010];
int maze[100][100],ans[100][100],n;
int calc(int x,int y);
int possible(int x,int y);


int main()
{
    ios
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>maze[i][j];
            ans[i][j]=0;
        }
    }
    if(calc(0,0)==1)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else
    {
        cout<<"No solution possible";
    }
    return 0;
}

int calc(int x,int y)
{
    if((x==n-1)&&(y==n-1))
    {
        ans[x][y]=1;
        return 1;
    }
    if(possible(x,y))
    {
        ans[x][y]=1;
        if(calc(x+1,y)==1)
        {
            return 1;
        }
        if(calc(x,y+1)==1)
        {
            return 1;
        }
        ans[x][y]=0;
    }
    return 0;
}

int possible(int x,int y)
{
    if((x<0)||(x>=n))
    {
        return 0;
    }
    if((y<0)||(y>=n))
    {
        return 0;
    }
    if(maze[x][y]==1)
    {
        return 1;
    }
    return 0;
}
/*-----------------------------------------------------------------------*/
/*
--->  reverse(vec.begin(),vec().end());
*/
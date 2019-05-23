/*
    Written By - Bignubie
*/
#include<bits/stdc++.h>
#define int              long long
#define ll 	             long long 
#define pb               push_back
#define all(a)           a.begin(),a.end()
#define endl             '\n'
#define mp               make_pair
#define F                first
#define S                second
#define vi               vector<int>
#define len(s)           (int)s.length()
#define sz(s)            (int)s.size()
#define rep(i,a,b)       for(int i=a;i<b;i++)
#define bs               binary_search
#define lb               lower_bound
#define ub               upper_bound
#define mapi             map<int,int>
#define fat              998244353
#define small            100005
#define ios              ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int dp[1005][1005];
string a,s;
int solve(int n,int m)
{
    if(n==0||m==0)return 0;
    int &ans=dp[n][m];
    if(ans!=-1)return ans;
    if(a[n-1]==s[m-1])return ans=1+solve(n-1,m-1);
    return max(solve(n-1,m),solve(n,m-1));
}
signed main()
{
ios
int tests=1;
//cin>>tests;
while(tests--)
{
    memset(dp,-1,sizeof(dp));
    cin>>a>>s;
    cout<<solve(len(a),len(s));
}
}

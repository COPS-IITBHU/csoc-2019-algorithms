/**
 * @ Author: Lakshya Singh
 * @ Create Time: 1970-01-01 05:30:00
 * @ Modified by: Target_X
 * @ Modified time: 2020-04-17 10:56:48
 * @ Description:
 */
/*
    ______                      __              _  __
   /_  __/___ __________ ____  / /_            | |/ /
    / / / __ `/ ___/ __ `/ _ \/ __/            |   /
   / / / /_/ / /  / /_/ /  __/ /_             /   |
  /_/  \__,_/_/   \__, /\___/\__/ ______     /_/|_|
                /____/           /_____/
 */

#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>
#include <set>
#include <utility>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <climits>
#include <numeric>
#include <cstdio>
#include <chrono>
#include <complex>
#include <iomanip>
#include <stack>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repA(i, a, n) for (int i = a; i <= (n); ++i)
#define repD(i, a, n) for (int i = a; i >= (n); --i)
#define tr(a, x) for (auto &a : x)
#define all(c) c.begin(), c.end()

#define lld long long
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define f first
#define s second
#define sz(a) int((a).size())
#define present(c, x) (c.find(x) != c.end())
#define cpresent(c, x) (find(all(c), x) != c.end())

#define vi vector<lld>
#define si set<lld>
#define endl "\n"
#define int long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define minq priority_queue<int, vector<int>, greater<int>>
#define mem(a, val) memset(a, val, sizeof(a))
#define le(n) scanf("%d", &n)

#define MOD 1000000007
#define inf 1000000000000000001;
#define seva 1000007;

using namespace std;
stack<int> s1;

void dfs(int sr, bool visited[], vector<int> v1[])
{
    visited[sr] = 1;

    for (auto x : v1[sr])
    {
        if (!visited[x])
            dfs(x, visited, v1);
    }
    s1.push(sr);
}

void dfsUtil(int sr, bool visited[], vector<int> v1[])
{
    visited[sr] = 1;
    cout << sr << " ";
    for (auto x : v1[sr])
    {
        if (!visited[x])
            dfsUtil(x, visited, v1);
    }
}

int32_t main()
{

    /**
     *Enter number of vertices and edges in the first line of input
     *In next lines equal to number of edges enter vertices between which edge exists 
     *Indexing is 1 based
    **/
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, e;
    cin >> n >> e;
    vector<int> v1[n + 1];
    vector<int> v2[n + 1];

    int x, y;
    while (e--)
    {
        cin >> x >> y;
        v1[x].pb(y);
        v2[y].pb(x);
    }

    bool visited[n + 1] = {0};
    repA(i, 1, n)
    {
        if (!visited[i])
        {
            dfs(i, visited, v1);
        }
    }

    mem(visited, 0);
    cout << "Each strongly connected component" << endl;
    while (!s1.empty())
    {
        if (!visited[s1.top()])
        {
            dfsUtil(s1.top(), visited, v2);
            cout << endl
                 << flush;
        }
        s1.pop();
    }
}

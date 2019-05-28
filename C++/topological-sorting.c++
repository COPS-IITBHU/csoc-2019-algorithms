/*
Topological Sorting of a DAG
BY Ashish Kumar (ashishkr23438)
*/

#include "bits/stdc++.h"
#pragma GCC optimize "03"
using namespace std;

#define int long long int
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define rep(i,a,b) for (int i = a; i < b; ++i)
#define dbg(x) { cerr<<"> "<<#x<<": "<<x<< endl; }
#define dbg2(x,y) { cerr<<"> "<<#x<<": "<<x<<" , "<<#y<<": "<<y<<endl; }
#define dbg3(x,y,z) { cerr<<"> "<<#x<<": "<<x<<" , "<<#y<<": "<<y<<" , "<<#z<<": "<<z<<endl; }
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#ifndef LOCAL
#define endl '\n'
#endif

const int N  = 1e5+5;

vector <int> g[N];
int state[N], flag = 0;
stack <int > s;

// state[]: 0 - not visited. 1 - processing node. 2 - processed node. [To check cycle in graph]

void dfs (int n) {
    if (state[n]) return;
    state[n] = 1;
    for (auto i: g[n]) {
        if (state[i] == 1) flag = 1; // If cycle exits in graph, then topological sort is not possible.
        dfs (i);
    }
    state[n] = 2;
    s.push(n);
}

signed main(){
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif  
    IOS;

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
    }
    for (int i = 1; i <= n; i++) {
        if (!state[i]) dfs(i);
    }
    if (flag == 1) cout << "Topological Sort is not possible.";
    else {
        while(!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
    }
    return 0;
}
/*

Input: First line contains two integers n and m, denoting n nodes (1,2,...,n) and m edges. [1 <= n <= 100000]
       Next m lines contain two integers x and y denoting an edge from x to y. [1 <= x, y <= n]

SAMPLE INPUT: [8 nodes, 9edges]
8 9
1 4
1 2
4 2
4 3
3 2
5 2
3 5
8 2
8 6

SAMPLE OUTPUT:
8 7 6 1 4 3 5 2

*/
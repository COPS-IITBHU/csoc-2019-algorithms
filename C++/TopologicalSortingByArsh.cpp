
#include<bits/stdc++.h>
#define NODE 6
using namespace std;

int graph[NODE][NODE] = {
   {0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0},
   {0, 0, 0, 1, 0, 0},
   {0, 1, 0, 0, 0, 0},
   {1, 1, 0, 0, 0, 0},
   {1, 0, 1, 0, 0, 0}
};

void driverSort(int u, bool visited[], stack<int>&stk) {
   visited[u] = true;

   for(int v = 0; v<NODE; v++) {
      if(graph[u][v]) {
         if(!visited[v])
            driverSort(v, visited, stk);
      }
   }
   stk.push(u);
}

void topoSort() {
   stack<int> stk;
   bool vis[NODE];

   for(int i = 0; i<NODE; i++)
      vis[i] = false;

   for(int i = 0; i<NODE; i++)
      if(!vis[i])
         driverSort(i, vis, stk);

   while(!stk.empty()) {
      cout << stk.top() << " ";
      stk.pop();
   }
}

main() {
   cout << "After Topological Sorting the Nodes are: ";
   topoSort();
}

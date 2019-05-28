/*
topological sorting user has to input the no. of vertices and the adjacency matrix
*/

#include<stdio.h>
int adj[100][100],n,visited[100];
int stack[1000],top=-1;
void topological_dfs();
void visitallvertex(int);
void push(int);
int pop();
int main()
{
    printf("Enter no. of vertices :");
  scanf("%d",&n);

 printf("\nEnter adjacency matrix of the graph:");
 for(int i=0;i<n;++i)
 for (int j=0;j<n;++j) scanf("%d",&adj[i][j]);

 for(int i=0;i<n;++i) visited[i]= 0;
 //printf("Enter bfs(0) or dfs(1)?");
 topological_dfs();
return 0;}

void topological_dfs()
{ for (int i=0;i<n;++i)
 {if(visited[i]==0)
   visitallvertex(i);
//11

 }
 for(int i=0;i<n;++i) printf("%d ",pop());
}


void visitallvertex(int i)
{for (int j =0;j<n;++j) if(adj[i][j]==1&&visited[j]==0) visitallvertex(j);
 push(i);


}
void push(int i)
{
 stack[++top]=i;
//printf("  ###%d###",stack[top]);
visited[i]=1;
}

int  pop()
{if(top==-1) return -1;
else return stack[top--];

}





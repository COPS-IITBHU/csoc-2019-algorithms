//THis is Rat in a Maze Algorithm with movement in 2 Directions Forward and Down written by Tanishq Agarwal

#include<stdio.h>
#include<stdlib.h>

int checkarr(int arr[4][4],int x, int y)
{int n=4;
 if(x>=0 && x<n && y>=0 && y<n && arr[x][y]==1)
 return 1;
 else
 return 0;
}
int solvearr(int arr[4][4],int x,int y,int sol[4][4])
{if(x==3 && y==3)
{sol[x][y]=1;
return 1;
}

if(checkarr(arr,x,y)==1)
{sol[x][y]=1;
if(solvearr(arr,x+1,y,sol)==1)
return 1;
if(solvearr(arr,x,y+1,sol)==1)
return 1;
sol[x][y]=0;
return 0;}
}
int main()
{int arr[4][4]={{1,0,0,0},{1,1,0,1},{0,1,0,0},{1,1,1,1,}};
static int sol[4][4];
//0 for Not a Path Point and 1 for a Path Point
solvearr(arr,0,0,sol);

for(int i=0;i<4;i++)
{for(int j=0;j<4;j++)
printf("%d",sol[i][j]);
printf("\n");
}
}

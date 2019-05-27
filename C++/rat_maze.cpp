#include <bits/stdc++.h>

using namespace std;

 int n;
 int maze[100][100],solvedmaze[100][100];//number of rows and columns in maze


bool cango(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1)
        return true;
    else
        return false;
}
bool solvingfunc( int x, int y)
{
    if(x==n-1 && y==n-1)
    {
        solvedmaze[x][y]=1;
        return true;
    }
    if(cango(x,y)==true)
    {
        solvedmaze[x][y]=1;
        if(solvingfunc(x+1,y)==true)
            return true;
        if(solvingfunc(x,y+1)==true)
            return true;
        solvedmaze[x][y]=0;
        return false;
    }
}
bool HelpRatSolveMaze()
{
   int i, j;
   for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            solvedmaze[i][j]=0;
        }
    }
    if(solvingfunc(0,0)==false)
       {
           cout << "NO SOLUTION" ;
           return false;
       }
    else
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
           cout << solvedmaze[i][j]<< " ";
        }
        cout << '\n';
    }

    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int i,j;
              // input maze
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            cin >> maze[i][j];
        }
    }
    HelpRatSolveMaze();
    return 0;
}


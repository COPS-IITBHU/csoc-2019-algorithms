#include<bits/stdc++.h>
using namespace std;

int max (int a,int b){
  if(a>b)return a;
  else return b;

}

// n is the number of eggs and k is the number of floors
int findFloor(int n, int k)
{
  // stores the results of egg from differenr floors
  int result[n+1][k+1];

  //stores temporary result
  int res;

  int i,j,x;

  // a minimum 1 test is needed from floor 1st and no test in floor 0
  for( i=1;i<n+1;i++)
  {
    result[i][1]=1;
    result[i][0]=0;
  }

  //if egg left is only one then you need to check all the remaining floors below the one which broke the eggs
  for(j=1;j<k+1;j++)
  {
    result[1][j]=j;
  }

  //now use dp to solve it
  for( i=2; i<n+1;i++)
  {
    for (j = 2; j < k+1; j++)
    {
      result[i][j]=INT_MAX; //to store the maximum value of int
      for (int x = 1; x < j+1; x++) {
        res = 1 + max(result[i-1][x-1],result[i][j-x]);
        if(res<result[i][j])
          result[i][j]=res;

      }

    }
  }
  //the final result is stored here
  return result[n][k];



}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;

    cout<<"Enter the number of eggs and floors";
    cin >> n >> k;
    cout<<'\n';

    cout<<"Trials Needed in worst case is:"<<findFloor(n,k);

}

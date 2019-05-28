#include <bits/stdc++.h>

using namespace std;

//Function to calculate longest increasing subsequence
void func(int A[], int n)
{
  int i,j,k=0,m,temp;
  int max=0,B[100005],S[100005];
  for ( i = 0; i < n-1; ++i)
  { 
    temp=A[i];
    B[k]=temp;
    k++;
    for ( j = i+1; j < n; ++j)
    {
      if(A[j]>temp)
      { 
        
        B[k]=A[j];
        k++;
        temp=A[j];
       
      }
      if(k>max)
      { 
        for ( m = 0; m<k; ++m)
        {
          S[m]=B[m];
        }
        max=k;
      }
      
    }
    k=0;
  }


if(n==1)
{
  max=1;
  S[0]=A[0];
}
cout<<"Length of longest subsequence : "<<max<<endl;
cout<<"Longest subsequence : ";

for (int i = 0; i < max; ++i)
{
  cout<<S[i]<<" ";
}


}



int main()
{
     
  int n;
  cin>>n;
  int A[n];
  for (int i = 0; i < n; ++i)
  {
    cin>>A[i];
  }
  func(A,n);
  return 0;
}
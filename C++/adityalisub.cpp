#include <bits/stdc++.h>
using namespace std;
#define FAST std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define hell 1000000007
#define PI 3.14159265358979323844
#define mp make_pair
#define pb push_back
#define pb push_back
#define ppb pop_back
#define rep(i,a,n)  for(int i=a ; i<n ; i++)
#define repe(i,a,n) for(int i=a;i<=n;i++)
#define ll long long
#define ld long double 
#define pii std::pair<int, int> 
#define pll std::pair<ll, ll>  
#define vi vector<int>  
#define vvi vector<vi > 
#define vii vector<pii >
#define itv for(auto it= v.begin(); it != v.end(); ++it )
#define present(container, element) (container.find(element) != container.end())
#define cpresent(container, element) (find(ALL(container),element) != container.end())

void lisub(int a[], int n)
{ 
    int i,j,mx=0,sseq[n],mi=0,mx1;
    int b[n];
    for(i=0;i<n;i++)
        b[i]=1;

   rep(i,1,n)
    {
    rep(j,0,i)
     {
     if((a[i]>a[j]) && (b[i]<b[j]+1))
        {
         b[i]=b[j]+1;
        }
        }
      }

   rep(i,0,n)              //loop using my macros
    {
      mx=max(mx,b[i]);
    }

    mx1=mx;
     rep(i,0,n)
    {
        if(mx==b[i])
            mi=i;
    }

    sseq[0]=a[mi];
    int l=1;

    for(int i=mi-1;i>=0;i--)
    {
    if((a[i]<a[mi])&&(b[i]+1==b[mi]))
    {
    sseq[l]=a[i];
    l++;
    mi=i;
    }
    }



    cout<<"THE LENGTH OF LONGEST INCREASING SUBSEQUENCE IS:- "<< mx<<endl;
 
    cout<< "The LONGEST INCREASING SUBSEQUENCE ELEMENTS ARE:- ";
    for(int i=l-1;i>=0;i--)
    {
        cout<< sseq[i]<< " ";
    }
  
 
}

void solve()
{ 
  
    int i,n;
    cout<<"Enter the no. of elements ";
    cin>>n;
 
    int a[n];  
 
    cout<<"Enter the values of elments:"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
 
    lisub(a,n);
 
} 



  int main()
{ 
   
  int t=1;
      while(t--)
    {
       
        solve();           
}

 return 0;
}
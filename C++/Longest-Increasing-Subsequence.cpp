#include <bits/stdc++.h> 
using namespace std; 
void lis(int *a, int n) 
{ 
    int i,j,maxi=1;
    vector<int> v[n]; 
    v[0].push_back(a[0]); 
    for(i=1;i<n;i++) 
    { 
        for (j=0;j<i;j++) 
        { 
            if ((a[i]>a[j])&&(v[i].size()<=v[j].size())) 
                v[i]=v[j]; 
        } 
        v[i].push_back(a[i]); 
        if(v[i].size()>maxi)
            maxi=v[i].size();
    }
    cout<<"Length of Longest Increasing Subsequence is - "<<maxi<<endl;
    cout<<"Longest Increasing Subsequence is:- ";
    for(i=0;i<n;i++)
    {
        if(v[i].size()==maxi)
        {
            for(j=0;j<maxi;j++)
                cout<<v[i][j]<<" ";
            return;
        }
    }
} 
int main() 
{ 
    int i,n;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    lis(a,n); 
    return 0; 
} 

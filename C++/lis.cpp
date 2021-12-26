#include<bits/stdc++.h>
#define lli long long int
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    vector<int> t(n,1);int max=0;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(v[i]>v[j]&&t[i]<t[j]+1)
            {
                t[i]=t[j]+1;
            }
        }
        if(t[i]>max)
        max=t[i];
    }
    cout<<max<<endl;
}

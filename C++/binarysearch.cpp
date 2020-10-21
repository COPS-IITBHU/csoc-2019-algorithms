#include<iostream>
using namespace std;
int main()
{
    int n,h,l,i,j,t,c;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n;i++){
        for(j=i+1;j!=n;j++){
            if(a[j]<a[i])
                swap(a[i],a[j]);
        }
    }
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cin>>t;
    l=0,h=n-1;
    while((a[l]!=t)&&(a[h]!=t)){
        //c=(l+h)/2; c will go out of range for big value of l and h
        c = l + (h-l)/2;
        if(a[c]<t){
            l=c;
        }
        else{
            h=c;
        }
    }
    if(a[l]==t)
        cout<<l;
    else if(a[h]==t)
        cout<<h;
}

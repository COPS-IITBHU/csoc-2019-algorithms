#include<bits/stdc++.h>
using namespace std;
float median(float a[],int n)
{
    float p;
     if (n % 2 == 0) 
        p=(a[n / 2] +  
                a[n / 2 - 1]) / 2; 
    else
    p=a[n / 2]; 
    return p;
} 
float diverge(float a[],float b[],int n)
{
    if(n==2)
    return (max(a[0],b[0])+min(a[1],b[1]))/2;
    float m1=median(a,n);
    float m2=median(b,n);
    if((int)m1==(int)m2)
    return m1;
    if(m1<m2)
    {
        if (n % 2 == 0) 
            return diverge(a + n / 2 - 1,  
                             b, n - n / 2 + 1); 
        return diverge(a + n / 2,  
                         b, n - n / 2); 
    }
    if(m2<m1)
    {
        if (n % 2 == 0) 
        return diverge(b + n / 2 - 1,  
                         a, n - n / 2 + 1); 
    return diverge(b + n / 2,  
                     a, n - n / 2); 
    }
    
}

int main()
{
    int n;float m;
    cout<<"\nenter number of elements in each array(equal) "<<endl;
    cin>>n;
    float a[n],b[n];
    cout<<"\nenter first sorted array \n";
    for(int i=0;i<n;i++)
    cin>>a[i];
    cout<<"\nenter second sorted  array \n";
    for(int i=0;i<n;i++)
    cin>>b[i];
    if(n==0)
    cout<<"empty array ";
    else if(n==1)
    m=(a[0]+b[0])/2;
    else
    m=diverge(a,b,n);
    cout<<"\nthe median of the sorted array of the two arrays is "<<m;
    
}

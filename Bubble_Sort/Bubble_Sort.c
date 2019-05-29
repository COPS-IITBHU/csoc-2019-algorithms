//Abhishek Kumar

#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int a[],int n)
{
    int temp=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n-i-1;++j)
        {
            if(a[j]>a[j+1])
            {
               temp=a[j];
               a[j]=a[j+1];
               a[j+1]=temp;
            }
        }
    }
}
int main()
{
    int arr[10]={5,4,6,12,1,8,38,3,22,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    BubbleSort(arr,n);
    for(int i=0;i<n;++i)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}

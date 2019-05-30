//This is Bubble Sort Algorithm

#include<stdio.h>
#include<stdlib.h>

int main()
{int n;
printf("Enter No. of Elements\n");
scanf("%d",&n);
int *arr;
arr=(int*)calloc(n,sizeof(int));
printf("Enter Elements\n");
for(int i=0;i<n;i++)
scanf("%d",&arr[i]);

for(int i=0;i<n;i++)
{for(int j=i+1;j<n;j++)
{if(arr[i]>arr[j])
{int temp=arr[j];
arr[j]=arr[i];
arr[i]=temp;}}
}

for(int i=0;i<n;i++)
{printf("%d ",arr[i]);}
}

//This is Insertion Sort Algorithm written by Tanishq Agarwal

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

for(int i=1;i<n;i++)
{int temp=arr[i];
int j=i-1;
while(j>=0&&arr[j]>temp)
{arr[j+1]=arr[j];
j=j-1;
}
arr[j+1]=temp;
}

for(int i=0;i<n;i++)
{printf("%d ",arr[i]);
}
}

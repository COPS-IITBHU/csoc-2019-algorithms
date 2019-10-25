#include<stdio.h>
int main()
{
int i,n,j;
printf("enter the size of array\n");
scanf("%d\n",&n);
int a[n];
printf("enter the elements in the array\n");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
printf("enter any integer you want to search in array");
scanf("\n%d",&j);
for(i=0;i<n;i++)
{
if(j==a[i])
{
printf("number found in array");
break;
}
}
if(i==n-1);
printf("number not found in array");
return 0;
}

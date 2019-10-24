#include<stdio.h>
int main()
{
int i,j,k;
printf("enter i");
scanf("%d\n",&i);
int a[i];
for(j=0;j<i;j++)
{
scanf("%d",&a[j]);
}
printf("enter value of k to test it is element of array\n");
scanf("%d",&k);
for(j=0;j<i;j++)
{
if(a[j]==k)
{
printf("k is a element in array");
break;
}
}
if(j==i)
printf("k is not element of array");
return 0;
}

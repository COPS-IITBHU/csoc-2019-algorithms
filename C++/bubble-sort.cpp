#include<stdio.h>
int main()
{
  int a[10],i,n,min,j,temp,flag;
  printf("enter the no of elements of the array");
  scanf("%d",&n);
  printf("\nenter the elements of the array");
  for (i=0;i<n;i++)
    scanf("%d",&a[i]);
  for(i=0;i<n-1;i++)
   { min=a[i];
     for(j=i;j<n;j++)
        if(a[j]<=min)
           {
              min=a[j];
              flag=j;
           }
     temp=a[i];
     a[i]=a[flag];
     a[flag]=temp;
    }
    printf("\nthe sorted array is");
    for(i=0;i<n;i++)
      printf(" %d",a[i]);
   return 0;
  }

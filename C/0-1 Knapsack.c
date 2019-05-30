//This is 0-1 Knpasack Algorithm by Tanishq Agarwal

#include<stdio.h>
#include<stdlib.h>

int max(int a, int b)
{return (a>b)?a:b;}
int knap(int capa, int weight[], int value[], int n)
{if(n==0||capa==0)
return 0;

if(weight[n-1]>capa)
return knap(capa,weight,value,n-1);

else return max(value[n-1]+knap(capa-weight[n-1],weight,value,n-1),knap(capa,weight,value,n-1));
}

int main()
{int n;
printf("Enter No of Elements\n");
scanf("%d",&n);
int *value=(int*)calloc(n,sizeof(int));
printf("Enter Value\n");
for(int i=0;i<n;i++)
{scanf("%d",&value[i]);}
int *weight=(int*)calloc(n,sizeof(int));
printf("Enter Weight\n");
for(int i=0;i<n;i++)
{scanf("%d",&weight[i]);}
int capa;
printf("Enter Capacity\n");
scanf("%d",&capa);

int TotalValue=knap(capa,weight,value,n);
printf("%d",TotalValue);
}

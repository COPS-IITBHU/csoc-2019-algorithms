//This is linear Search Algorithm C Program Written by Tanishq Agarwal

#include<stdio.h>
#include<stdlib.h>


int main()
{int n;//Number of Terms
 printf("How many terms you want to enter");
 scanf("%d",&n);
 int *arr;
 arr= (int*)calloc(n,sizeof(int));
 for(int i=0;i<n;i++)
 {scanf("%d",&arr[i]);}
 int no;
 printf("Enter No. you want to search");
 scanf("%d",&no);
 int flag=0;
 
 for(int i=0;i<n;i++)
 {if(arr[i]==no)
 {printf("No found at location %d",i+1);
 flag=1;}
 else
 {continue;}
 }
 if(flag==0)
 {printf("Element not found");}
}

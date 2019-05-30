//This is Binary Search Algorithm written by Tanishq Agarwal

#include<stdio.h>
#include<stdlib.h>
int binarysearch(int arr[],int nu,int no);
int main()
{int no;//No of Elements
printf("How many no of sorted elements do you want to enter\n");
scanf("%d",&no);
int *arr;
arr=(int*)calloc(no,sizeof(int));
for(int i=0;i<no;i++)
{scanf("%d",&arr[i]);}
int nu;
printf("Enter No. you want to Search\n");
scanf("%d",&nu);
int return1=binarysearch(arr,no-1,nu);
if(return1==0)
{printf("Element not Found");}
else
{printf("Element found at Location %d",return1+1);}}

int binarysearch(int arr[], int no, int nu)
{if (no >= 0) { 
        int mid = (no) / 2; 

        if (arr[mid] == nu) 
            return mid; 

        if (arr[mid] > nu) 
            return binarysearch(arr, mid - 1, nu); 

        return binarysearch(arr, mid + 1, nu); 
    } 
 
}

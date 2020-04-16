#include<iostream>
using namespace std;

void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}

void bubblesort(int arr[],int n)
{
	int i,j=0;
	for(j=0;j<n-1;j++){
		
	int flag=0;
	for(i=0;i<n-j-1;i++)
	{
		if(arr[i]>arr[i+1])
		{
			swap(&arr[i],&arr[i+1]);
			flag=1;
		}
		
	}
	if(flag==0)
		break;
	}
}
int main()
{
	int arr[]={1,3,4,2,5,8,9,6,7};
	int n;
	n=sizeof(arr)/sizeof(arr[0]);
	bubblesort(arr,n);
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	
	return 0;
}

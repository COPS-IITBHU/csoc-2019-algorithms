#include <stdio.h>
#include <iostream.h>

void bubble_sort(int a[]);
int main()
{
	int n;  //number of elements in array
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	

		
	
	void bubble_sort(int a[])   //for ascending order
	{
		int temp;
		for(int i=0;i<n-1;i++)
		for(int j=1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;			
				
			}
			
		}
      
      
      
      
     for(int k=0;k<n;k++)
     {
     	cout<<a[k]<<" ";
	 }
       
	}
	
	cout<<"sorted array:"<<endl;
	bubble_sort(a[n]);
	
	
	return 0;
	
	
}

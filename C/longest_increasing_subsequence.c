#include<stdio.h>

void find_longest_inc_subseq(int size, int array[])
{
	int len_lis[size];                 
	len_lis[0]=1;
	
	for(int i=1;i<size;i++)
	{
		len_lis[i]=1;              //initialising all len_lis elements to 1
		for(int j=0;j<i;j++)
		{
		    	
			if(array[i]>array[j]&& len_lis[j]+1>len_lis[i])
				len_lis[i]=len_lis[j]+1;
		}
	}


int index=0,length=-1;         //index is the index of the largest element in lis
	for(int i=0;i<size;i++)        //length is the length of lis
	{
		if(len_lis[i]>length)
			{length=len_lis[i];index=i;}
	}
	int lis[100000];               //The array to store lis
	lis[0]=array[index];
	int pointer=1;
	for(int i=index-1;i>=0;i--)
	{
		if(array[i]<array[index]&&len_lis[i]==len_lis[index]-1)
			{lis[pointer]=array[i];
			pointer++;
			index=i;}
	}
	
  
  printf("The longest increasing subsequence is \n ");
	for(int i=pointer-1;i>=0;i--)
	{
		printf("%d ", lis[i]) ;
	}
	printf("\n");
	printf("The length of the longest increasing subsequence is \n ");
	printf("%d",length); 
}



int main()
{
	int size;
	scanf("%d",&size);               //Input the length of array
	int array[100000];
	for(int i=0;i<size;i++)
	{
		scanf("%d",&array[i]);       //Input the array
	}
	find_longest_inc_subseq(size,array);
}

#include<bits/stdc++.h>

using namespace std;

void subs(int arr[100000],int dp[100000], int n);
int sub[100000];
	
int lon_inc_subs(int n, int arr[100000])
{
	int dp[100000];
	for(int i=0;i<n;i++)
	{
		dp[i]=1;
	}
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(arr[i]>arr[j]&& dp[j]+1>dp[i])
				dp[i]=dp[j]+1;
		}
	}
	int max_index=0,max=*max_element(dp,dp+n);
	for(int i=0;i<n;i++)
	{
		if(max==dp[i])
			max_index=i;
	}
	sub[0]=arr[max_index];
	int k=1;
	for(int i=max_index-1;i>=0;i--)
	{
		if(arr[i]<arr[max_index]&&dp[i]+1==dp[max_index])
			{sub[k]=arr[i];k++;max_index=i;}
	}
	cout<< "The longest increasing subsequence is: ";
	for(int i=k-1;i>=0;i--)
	{
		cout<< sub[i]<< " ";
	}
	cout<< endl;
	cout<< "The length of the longest increasing subsequence is: ";
	return *max_element(dp,dp+n);
}



int main()
{
	int n;
	cin>> n;
	int arr[100000];
	for(int i=0;i<n;i++)
	{
		cin>> arr[i];
	}
	cout<< lon_inc_subs(n,arr);
}

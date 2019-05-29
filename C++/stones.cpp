

#include<bits/stdc++.h>
using namespace std;
void subs(int a[n],int new_a[n], int n);
int n;
cin>>n;
int sub[n];
	
int final_subseq(int n, int a[n])
{
	int new_a[n];
	for(int i=0;i<n;i++)
	{
		new_a[i]=1;
	}
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(a[i]>a[j]&& new_a[j]+1>new_a[i])
				new_a[i]=new_a_a[j]+1;
		}
	}
	int mx_ptr=0,max=*max_element(new_a,new_a+n);
	for(int i=0;i<n;i++)
	{
		if(max==new_a[i])
			mx_ptr=i;
	}
	sub[0]=a[mx_ptr];
	int k=1;
	for(int i=mx_ptr-1;i>=0;i--)
	{
		if(a[i]<a[mx_ptr]&&new_a[i]+1==new_a[mx_ptr])
			{sub[k]=a[i];k++;mx_ptr=i;}
	}
	cout<< "The longest increasing subsequence is: ";
	for(int i=k-1;i>=0;i--)
	{
		cout<< sub[i]<< " ";
	}
	cout<< endl;
	cout<< "The length of the longest increasing subsequence is: ";
	return *max_element(new_a,new_a+n);
}



int main()
{
	int n;
	cin>> n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>> a[i];
	}
	cout<< final_subseq(n,a);
}
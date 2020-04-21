#include<bits/stdc++.h>
int a[100][100]={{0}};
int N;
using namespace std;
bool is_attacked(int x,int y)// Submitted by Purushottam Tiwari (Github:- m-e-l-u-h-a-n)
{
	//checking in rows and columns
	for(int i=0;i<N;i++)
	{
		if(a[i][y]==1)
		return true;
		if(a[x][i]==1)
		return true;
	}
	//checking diagonally
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if((i+j==x+y)&&(a[i][j])==1)
			return true;
			if((i-j==x-y)&&(a[i][j])==1)
			return true;
		}
	}
	return false;
}
bool N_queens(int n)
{
	if(n==0)
	return true;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(!is_attacked(i,j)&&a[i][j]!=1)
			{
				a[i][j]=1;
				if(N_queens(n-1))//checking if a[i][j] is a suitable place for putting queen
				return true;
				else
				a[i][j]=0;//if above function returns false then we undo our changes
			}
		}
	}
	return false;
}
int main()
{
	cout<<"Enter the (order n) of the chess board: ";
	cin>>N;
	if(N>100)
	cout<<"Too high value of n,please enter a value less than 100!";
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			a[i][j]=0;
		}
	}
	if(N_queens(N))
	{
		cout<<"YES\n";
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				cout<<a[i][j]<<' ';
			}
			cout<<'\n';
		}
	}
	else
	cout<<"Not Posible to put !";
	return 0;
}

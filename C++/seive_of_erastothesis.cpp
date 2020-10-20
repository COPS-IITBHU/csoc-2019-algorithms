#include<bits/stdc++.h>
#define int long long
using namespace std;
//If n numbers are given then tell the number of primes among them and list them
//sieve of erastothesis
bool prime[500001];
void seive_of_eras(int n)
{
    prime[0]=prime[1]=true;
   	for(int i=2;i<=n;i++)
   	{
   		if(prime[i]==false)
   		{
   			for(int j=2*i;j<=n;j+=i)
   			{
  				prime[j]=true;
   			}
   		}
   	}
}
int main()
{
	seive_of_eras(500000);
	int n;
	cin>>n;
	int ar[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>ar[i];
	}
	int num_of_primes=0;
	vector <int> list_of_primes;
	for (int i = 0; i < n; ++i)
	{
		if(prime[ar[i]]==false)
		{
			num_of_primes++;
			list_of_primes.push_back(ar[i]);
		}
	}
	cout<<num_of_primes<<endl;
	for (int i = 0; i < num_of_primes; ++i)
	{
		cout<<list_of_primes[i]<<" ";
	}
	cout<<endl;
	return 0;
}
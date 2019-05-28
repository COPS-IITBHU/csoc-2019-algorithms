#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
void rabin_karp(string text,string pattern);
bool linear_compare(string text,string pattern,ll i);
int main()
{	
	
	string text,pattern;
	cout<<"Enter text "<<endl;
	cin>>text;
	cout<<"Enter pattern "<<endl;
	cin>>pattern;
	rabin_karp(text,pattern);
}

void rabin_karp(string text,string pattern)
{
	ll hash_pattern=0,hash_text=0,i;
	ll lenp=pattern.size();
	ll lent=text.size();
	ll prime=33;
	for(i=0;i<lenp;i++)
	{
		hash_pattern = hash_pattern*prime + pattern[i];
		hash_text    = hash_text*prime    + text[i];
	}
	for(i=0;i<=lent-lenp;i++)
	{
		if(hash_text==hash_pattern  && linear_compare(text,pattern,i))
		{
			cout<<"Pattern found at "<<i<<endl;
		}
		if(i<lent-lenp) hash_text = prime*( hash_text - text[i]*(pow(prime,lenp-1)) ) + text[i+lenp]; 
	}
}

bool linear_compare(string text,string pattern,ll i)
{
	for (ll j=0;j<pattern.size();j++)  
    {  
        if (text[i+j]!=pattern[j])  return false;
           
    }
    return true;
}


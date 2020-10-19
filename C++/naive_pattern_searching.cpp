//naive pattern searching - abee62
#include<bits/stdc++.h>
using namespace std;
int main()
{
	char s[1000],pat[1000],flag=0;
	cout<<"Enter the complete text in which you want to search\n";
	cin.getline(s,1000);
	cout<<"Enter the pattern\n";
	cin.getline(pat,1000);
	int a,b;
	a=strlen(s);
	b=strlen(pat);
	for(int i=0;i<=(a-b);i++ )
	{
		int j;
		for(j=0;j<b;j++)
		{
			if(s[i+j]!=pat[j])
				break;
		}
		if(j==b)
			{cout<<"Pattern found at index "<<i<<endl;
			flag=1;}

	}
	if(flag==0)
		cout<<"Pattern not found";

	return 0;

}
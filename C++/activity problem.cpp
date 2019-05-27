#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	
	cin>>n;//takes the total number of activities as the input
	vector< int >v1(n);
	vector< int >v2(n);
	vector< int >v3;
	
	for(int i=0;i<=n-1;i++)
	{
		cin>>v1[i]>>v2[i];
		v3.push_back(v2[i]-v1[i]);//pushes the difference between starting and ending time
	}
    int c;
    
    cin>>c;//the number of activities user wants to do.
    int k;
    for(int j=1;j<=c;j++)
    {
        k=min_element(v3.begin(),v3.end())-v3.begin();
        cout<<"starting time:"<<v1[k]<<" "<<"ending time"<<v2[k]<<"\n";//prints starting and ending time of the activity user can do
        v3.erase(v3.begin()+k);
        v1.erase(v1.begin()+k);
        v2.erase(v2.begin()+k);
        
    }
}

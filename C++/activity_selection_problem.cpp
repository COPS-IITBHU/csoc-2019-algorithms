#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;//input the number of activities
    vector< int >s(n);
    vector< int >p(n);
    int a,b;
    vector<pair<int,pair<int,int> > >v;
    vector<pair<int,int> >v1;
    for(int i=0;i<=n-1;i++)
    {
        cin>>s[i]>>p[i];
        v.push_back(make_pair(i+1,make_pair(s[i],p[i])));
        v1.push_back(make_pair(p[i],s[i]));
    }
    sort(v1.begin(),v1.end());//sort the activities in ascending order of finishing time
    cout<<"starting time:"<<v1[0].second<<" "<<"finishing time"<<v1[0].first<<"\n";
    for(int j=1;j<=n-1;j++)
    {
        if(v1[j].second>=v1[j-1].first)//if the starting time of the second activity is greater than or equal to the first then print it otherwise delete it.
        cout<<"starting time:"<<v1[j].second<<" "<<"finishing time"<<v1[j].first<<"\n";
        else
        {
            v1.erase(j+v1.begin());
            n--;
            cout<<"starting time:"<<v1[j].second<<" "<<"finishing time"<<v1[j].first<<"\n";
            
        }
    }
}

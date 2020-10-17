#include<iostream>
#include<algorithm>
using namespace std;
// own comperator function
bool func_name(pair<int, int> p1, pair<int, int> p2) 
{ 
    if(p1.second > p2.second ){
		return 0;
	}  
	if(p1.second == p2.second){
		if(p1.first>p2.first)
			return 0;
		else
			return 1;
	}
    return 1; 
} 
int main() {
    // testcase
	int t;
	cin>>t;
	while(t--){
        // no of activities
		int n;
		cin>>n;
		int activity = 1;
        // start and end times of activities
		pair<int, int> p[n];
		for(int i=0;i<n;i++){
			cin>>p[i].first>>p[i].second;
		}
        // sorting using the comperator
		sort(p, p+n, func_name);

		for(int i=1;i<n;i++){
			//cout<<p[i].first<<" "<<p[i-1].second<<"\n";
			if(p[i].first>=p[i-1].second)
				activity++;
		}
		cout<<activity<<"\n";
	}
	return 0;
}
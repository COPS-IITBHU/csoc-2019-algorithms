#include <bits/stdc++.h> 
using namespace std; 
bool Compare( pair<int,int>v1,pair<int,int>v2) 
{ 
    return (v1.second< v2.second); 
}  
  int main() 
{ 
    vector<pair<int,int>>v = {{5, 9}, {1, 2}, {3, 4}, {0, 6},{5, 7}, {8, 9}}; 
    int n = v.size();
    sort(v.begin(), v.end(), Compare); // sorting based upon the activity end time 
    cout << "Following activities are selected : "; 

    int i = 0; 
    cout << "(" << v[i].first << ", " << v[i].second<< "), "; 
    
    for (int j = 1; j < n; j++) 
    { 
      
      if (v[j].first >= v[i].second) 
      { 
          cout << "(" << v[j].first << ", "<< v[j].second << "), "; 
          i = j; 
      } 
    }  
    return 0; 
} 

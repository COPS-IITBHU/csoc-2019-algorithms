#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
   int a;
    cin>>a;
    int arr[a]; vector < int> v;
    for(int i=0;i<a;i++) {cin>>arr[i];  v.push_back(1);}
    for(int i=1;i<a;i++){
        for(int j=0;j<i;j++){
           if(arr[j]<arr[i] && v[i]<v[j]+1) {
               v[i]=v[j]+1;
               }
        }
    }
    cout<< *max_element(v.begin(),v.end());
    return 0;
}

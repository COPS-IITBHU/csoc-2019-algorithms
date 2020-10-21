#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
   int a;
    cin>>a;
    int arr[a]; int n;
    for(int i=0;i<a;i++) {
        cin>>arr[i];  
    }
    cin>>n; //number to be searched
    int l=0;int u=a-1; 
    while(l<=u){
        int mid = l + (u - l) / 2; 
        if (arr[mid] == n) 
        {cout<<"Found";  return 0;}
        if (arr[mid] > n) 
            u=mid-1;
        else
       l=mid+1;
    }
    cout<<"Not found";
    return 0;
}

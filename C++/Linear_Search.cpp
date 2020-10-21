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
    for (int i = 0; i < a; i++)
    {if (arr[i] == n)
        { cout<<"Found";return 0;}} 
    cout<<"Not found";
    return 0;
}
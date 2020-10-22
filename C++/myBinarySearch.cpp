#include<bits/stdc++.h>
using namespace std;
int binarySearch1(int arr[],int l,int r,int x)
{
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
        if (arr[mid] == x) 
            return mid; 
        if (arr[mid] > x) 
            return binarySearch1(arr, l, mid - 1, x);  
        return binarySearch1(arr, mid + 1, r, x); 
}
}
// here the indexing of array starts at 1
int main()
{
    int arr[] = {1,4,7,8,9};
    int x = 9;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch1(arr,0,n-1,x);
    (result == -1) ? cout << "element is not present in array" : cout << "element is present at index " << result+1; 
    return 0;
}
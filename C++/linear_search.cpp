#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,num;
  printf("Enter the total no. of elements: \n");
  scanf("%d",&n);
  int a[n];
  printf("Enter the elements: \n");
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  printf("Enter the number you want to search: \n");
  scanf("%d",&num);
  for(int i=0;i<n;i++){
    if(a[i] == num){
      printf("Element found at location: %d",i+1);
      break;
    }else if(i == n-1){
      printf("Element not found.");
    }
  }
  return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n,m;
  scanf("%d",&m);
  int arr[m];
  for(int i=0;i<m;i++)
  {
      scanf("%d",&arr[i]);
  }
  scanf("%d",&n);
  for(int i=0;i<m;i++)
  {
      if(arr[i]==n)
      {
        return printf("Yes");
      }
  }
  printf("No");
    return 0;
}

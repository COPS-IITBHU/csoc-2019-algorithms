// Algorith to find Median of two sorted arrays.//
// Array is to be entered in algorithm
//Used pointers to solve it//
#include <stdio.h>

int max(int a, int b)
{
   return ((a > b) ? a : b);
}
int min(int a, int b)
{
   return ((a < b) ? a : b);
}
int median(int arr[], int size)
{
   if (size % 2 == 0)
         return (arr[size/2] + arr[size/2-1])/2;
   else
         return arr[size/2];
}
int median2SortedArrays(int arr1[], int arr2[], int size)
{
   int med1;
   int med2;
   if(size <= 0) return -1;
   if(size == 1) return (arr1[0] + arr2[0])/2;
   if (size == 2) return (max(arr1[0], arr2[0]) + min(arr1[1], arr2[1])) / 2;

   med1 = median(arr1, size);
   med2 = median(arr2, size);

   if(med1 == med2) return med1;

   if (med1 < med2)
   {
      return median2SortedArrays(arr1 + size/2, arr2, size - size/2);
   }
   else
   {
      return median2SortedArrays(arr2 + size/2, arr1, size - size/2);
   }
}

int main()
{
   int i,m,n;
   int arr1[] = {1, 5, 12, 24, 35};
   int arr2[] = {4, 8, 15, 18, 34};
   m = sizeof(arr1) / sizeof(arr1[0]);
   n = sizeof(arr2) / sizeof(arr2[0]);
	//------------- print original array ------------------
	printf("The given array - 1 is :  ");
	for(i = 0; i < m; i++)
	{
	printf("%d  ", arr1[i]);
    }
	printf("\n");
//------------------------------------------------------
	printf("The given array - 2 is :  ");
	for(i = 0; i < n; i++)
	{
	printf("%d  ", arr2[i]);
    }
	printf("\n");
//------------------------------------------------------
   printf("\nThe Median of the 2 sorted arrays is: %d",median2SortedArrays(arr1, arr2, n));
   printf("\n");
   return 0;
}

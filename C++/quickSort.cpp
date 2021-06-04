/* -Quick Sort is a sorting algorithm that follows Divide & Conquer Rule.
 *    -It sorts by selecting a random element as pivot & putting it at it's right position & putting smaller elements
 *     before it & large after it(ascending order). Following the procedure till we do not get a sorted array.  
 *    -We will be picking the high element as pivot.
 *    -Average case time complexity is O(nlogn).
 *    -Worst case timie complexity is O(n^2).
 *    -The given program is sorting them in ascending order.
 * */

#include <iostream>

using namespace std;

void swap(int*a, int*b)
{
      //Function for swapping two array elements
       int temp = *a;
       *a =*b;
       *b =temp;
}


int partition(int arr[], int low, int high)
{
      /*Partition function does the main work by selecting the pivot & arranging 
       *                                               it at it's proper place in the array*/
       int pivot = arr[high];                    // Last element of the array has been taken as pivot
       int i = low - 1;
       for(int j = low; j < high; j++)
     {
	
	        if(arr[j] < pivot)
	  {
	     
	                 i++;
	                 swap(&arr[i], &arr[j]);
	  }
	
     }
   
       swap(&arr[i+1], &arr[high]);
       return i+1;                               // Returning the arranged position of pivot in the array
}


void quickSort(int arr[], int low, int high)
{
   
       
       if(low < high)
     {
	                             
	        int pos = partition(arr, low, high);    // Calls partition to get the suitable position of pivot
	        quickSort(arr, low, pos-1);             // Calls quickSort again for first half
	        quickSort(arr, pos+1, high);            // Calls quickSort again for second half
     }
   
}


int main()
{
   
       int n;       // Size of the array
       scanf("%d", &n);
       int arr[n];
       for(int i = 0; i < n; i++)                  // Input of array elements
             scanf("%d", &arr[i]);
       quickSort(arr, 0, n-1);                     // quickSort function call
       for(int i = 0; i < n; i++)                  // Output of array elements
             printf("%d ",arr[i]);
       return 0;
}







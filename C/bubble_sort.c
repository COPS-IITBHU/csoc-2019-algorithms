// bubble sort in c 
#include <stdio.h> 
int main() 
{ 
    int arr[] = {60,75,80,85,25,35}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    bubbleSort(arr, n); 
    printf("Sorted array: \n"); 
    printArray(arr, n); 
    return 0; 
} 
void bubbleSort(int arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)       
      
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              {
                int t;
                t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;

              } 
} 
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
     
} 

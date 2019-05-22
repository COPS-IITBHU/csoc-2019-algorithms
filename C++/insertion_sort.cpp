// Insertion Sort is a sorting algorithm which functions as if you were sorting a deck of card by placing sorted cards in one
// hand and inserting other cards one by one in proper position in the sorted deck

#include <iostream>

using namespace std;

int main()
{   int j,num;
    int arr[] = {31, 41, 59, 26, 41, 58}; //Dummy array
    int size = sizeof(arr)/sizeof(arr[0]); //length of array
    for(int i = 1; i <= size; i++){ //starting with second element, a single element is always sorted
        num = arr[i];  //comparing every element behind it
        j = i-1;
        while(j >= 0 && arr[j]<num){ //until the right position for this element has been found
            arr[j+1] = arr[j]; //keep swapping
            j--;
        }
        arr[j+1] = num; //Insert the element
    }
    for(int i = 0; i < size; i++){
        cout << arr[i] << endl; //Output sorted array
    }
    return 0;
}

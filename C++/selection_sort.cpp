#include<iostream>
#include<climits>
using namespace std;
int min = INT_MAX;
void selection_sort(int ar[], int n){

    // n-1 only because last element gets sorted automatically
    for (int i = 0; i < n-1; i++){
        int min_index = i;
        // finding min in the unsorted array
        for (int j = i; j <= n - 1;j++){
            if(ar[j]<ar[min_index]){
                min_index = j;
            }
        }
        // swapping index i with min index
        swap(ar[i], ar[min_index]);
    }
}

int main() {

    int n;
    cin >> n;
    // initialising array
    int ar[1000];
    // taking input
    for (int i = 0; i < n;i++){
         cin >> ar[i];
    }
    selection_sort(ar, n);

        for (int i = 0; i < n;i++){
        cout << ar[i] <<" ";
    }
    return 0;
}
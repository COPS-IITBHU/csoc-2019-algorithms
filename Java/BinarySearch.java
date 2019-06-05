import java.util.Scanner;

class BinarySearch { 
    
    int binarySearch(int arr[], int l, int r, int x) 
    { 
        if (r >= l) { 
            int mid = l + (r - l) / 2; 
  
            if (arr[mid] == x) 
                return mid; 
  
            if (arr[mid] > x) 
                return binarySearch(arr, l, mid - 1, x); 
 
            return binarySearch(arr, mid + 1, r, x); 
        } 

        return -1; 
    } 

    public static void main(String args[]) 
    { 
        BinarySearch ob = new BinarySearch();
	Scanner input = new Scanner(System.in);
	System.out.println("Enter the total number of data to be entered");
	int n = input.nextInt(); 
        int[] arr = new int[n];
	System.out.println("Now enter the data");
	System.out.println("----Only numbers expected----");
	for(int i=0;i<n;i++)
	{
	    System.out.print((i+1)+" : ");
	    arr[i] = input.nextInt();
	}
	System.out.println("Enter the number to be searched for");
        int x = input.nextInt(); 
        int result = ob.binarySearch(arr, 0, n - 1, x); 
        if (result == -1) 
            System.out.println("Element not present"); 
        else
            System.out.println("Element found at position " + (result+1)); 
    } 
} 

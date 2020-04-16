class Static {
  int val;
  Static(this.val);
}
int _lis(List<int> arr, int n, Static max){
  if (n==1) return 1;
  int res, max_ending_here=1;
  for(int i=1; i<n; i++){
    res = _lis(arr,i,max);
    if ( arr[i-1]<arr[n-1] && res + 1 > max_ending_here){
      max_ending_here = res + 1;
    }
  }
  if(max.val < max_ending_here){
    max.val = max_ending_here;
  }
  return max_ending_here;
}

int lis(List<int> arr, int n){
  Static max = new Static(1); 
  _lis(arr,n,max);
  return max.val;
}

void main() {
  List<int> arr = [50, 3, 10, 7, 40, 80];
  int n = arr.length;
  var answer = lis(arr,n);
  print("Length og LIS is: ${answer}");
}
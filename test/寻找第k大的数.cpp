#include "fuckyou.h" 
template <typename T>
T find_kth_element(T arr[], int rk, const int len) {
  if (len <= 1) return arr[0];
  rk -= 1;
  srand(time(NULL)); 
  const T pivot = arr[rand() % len];
  int i = 0, j = 0, k = len;
  while (i < k) {
    if (arr[i] < pivot)
      swap(arr[i++], arr[j++]);
    else if (pivot < arr[i])
      swap(arr[i], arr[--k]);
    else
      i++;
  }
  if (rk < j) return find_kth_element(arr, rk, j);
  else if (rk >= k)
    return find_kth_element(arr + k, rk - k, len - k);
  return pivot;
}
template <class a>
int getlen(a& array){
	return (sizeof(array)/sizeof(array[0]));
}
int main(void){
	int ass[]={2,5,7,4,3,6,88,1,46};
	int fi =  find_kth_element(ass,8,(const int)getlen(ass));
	cout<<fi<<endl;
}





#include "fuckyou.h"
using namespace std;
template <typename T>
void quick_sort(T arr[], const int len) {
  if (len <= 1) return;
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
  quick_sort(arr, j);
  quick_sort(arr + k, len - k);
}
template <class T>
int len(T& array){
	return (sizeof(array)/sizeof(array[0]));
}
int main(void){
	int ass[]={2,4,7,3,2,45,33,1};
	const int len1 = len(ass);
	quick_sort(ass,len1);
	for(int i = 0;i<len1;i++){
		cout<<ass[i]<<endl; 
	}
}



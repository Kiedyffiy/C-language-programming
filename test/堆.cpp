#include "fuckyou.h"

void sift_down(int arr[], int start, int end) {
  int parent = start;
  int child = parent * 2 + 1;
  while (child <= end) { 
    if (child + 1 <= end && arr[child] < arr[child + 1]) child++;
    if (arr[parent] >= arr[child])
      return;
    else { 
      swap(arr[parent], arr[child]);
      parent = child;
      child = parent * 2 + 1;
      //sift_down(arr,child,end);
    }
  }
}

void heap_sort(int arr[], int len) {
  for (int i = (len - 1 - 1) / 2; i >= 0; i--)sift_down(arr, i, len - 1);
  // 先将第一个元素和已经排好的元素前一位做交换，再重新调整（刚调整的元素之前的元素），直到排序完毕
  for (int i = len - 1; i > 0; i--) {
    swap(arr[0], arr[i]);
    sift_down(arr, 0, i - 1);
  }
} 

int main(void){
	int as[]={2,6,4,45,23,99,3};
	heap_sort(as,7);
	for(int i = 0;i<7;i++){
		cout<<as[i]<<endl;
	}
	
	
} 

#include "bits/stdc++.h"
using namespace std;

const int N = 1000;
const int size = 50;
int bucket_size = size;//w / n + 1;
const int bucket_num = N/bucket_size +1; 
vector<int> bucket[21];
void insertion_sort(vector<int>& A) {
  for (int i = 1; i < A.size(); ++i) {
    int key = A[i];
    int j = i - 1;
    while (j >= 0 && A[j] > key) {
      A[j + 1] = A[j];
      --j;
    }
    A[j + 1] = key;
  }
} 

void bucket_sort(int a[],const int n) {

  for (int i = 0; i < bucket_num; ++i) {
    bucket[i].clear();
  }
  for (int i = 0; i < n; ++i) {
    bucket[a[i] / bucket_size].push_back(a[i]);
  }
  int p = 0;
  for (int i = 0; i < bucket_num; ++i) {
    insertion_sort(bucket[i]);
    for (int j = 0; j < bucket[i].size(); ++j) {
      a[p++] = bucket[i][j];
      //cout<<a[p]<<endl;
    }
  }
} 
int main(void){
	int as[]={23,344,352,34,128,35,890,349,120,123,45,657,342,568,453,334,537,158,953,567,876,359,975,127,231,23,79};
	const int n = (sizeof(as)/sizeof(as[0]));
	bucket_sort(as,n);
	for(int j = 0;j<n;j++){
		cout<<as[j]<<endl;
		
	}
	cout<<"总计"<<n<<"个数"<<endl; 
}

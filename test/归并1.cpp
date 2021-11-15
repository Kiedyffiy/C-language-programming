#include "fuckyou.h"
template <class T>
void merge(int ll, int rr,T& a){	
//  if (rr - ll <= 1){
//  	if((a[rr]<a[ll]))
//  	 std::swap(a[rr],a[ll]);
//  	return;
//  }
  int mid = ll + (rr - ll >> 1);
  if(rr-ll!=0){
  merge(ll, mid, a);
  merge(mid, rr, a);}
  int p = ll, q = mid, s = ll;
  int t[1000];
  while (s < rr) {
    if (p >= mid || (q < rr && a[p] > a[q])) {
      t[s++] = a[q++];
      // ans += mid - p;
    } else
      t[s++] = a[p++];
  }
  for (int i = ll; i < rr; ++i) a[i] = t[i];
  return;
} 
int main(void){
	int array[]={45,7,56,34,23,89,8,10};
	merge(0,7,array);
	for(int i = 0;i<8;i++){
		cout<<array[i]<<endl;
	}
}

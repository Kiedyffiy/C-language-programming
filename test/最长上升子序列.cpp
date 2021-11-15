#include "bits/stdc++.h"
using namespace std; 
//template<class syntax>
int a[10001],f[10001],n,ans;
int find(int l,int r,int ass){
	int mid;
while(l<r){
	mid =(l+r)/2;
	if(ass>=f[mid]){
		l = mid+1;
	}else{
		r = mid;
	}
}
	return l ;
}
int main(void){
	
//ios::sync_with_stdio(false);
	scanf("%d",&n);
	for(int i = 1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	f[1]=a[1];
	ans = 1;
	for(int i =2;i<=n;i++){
		if(a[i]>f[ans]){
			f[++ans]=a[i];
			continue;
		}else{
			int j = find(1,ans,a[i]);
			f[j]=a[i];
		}
	}
	int result = n-ans;
	printf("%d",result);
}


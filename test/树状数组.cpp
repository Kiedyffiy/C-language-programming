#include "bits/stdc++.h"
int lowbit(int i){
	return i&(~i+1);
}
void createtree(auto a[],auto b[]){   ///create the tree
	int n = sizeof(a)/sizeof(a[0]);
	for(int i = 1;i<=n;i++){
		b[i] += a[i];
		int j = i + lowbit(i); 
		if(j<=n)b[j]+=b[i];
	}	
}
void add(int x,int k,auto a[],auto b[]){
	while(x<=n){
	b[x] += k;	
	x += lowbit(x);
	}
}
int getsum(int x){
	int ans = 0 ;
	while(x>=1){
		ans = ans + b[x];
		x = x - lowbit(x);
	}
	return ans;
}
int main(void){
	
	
	
	
}

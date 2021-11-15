#include "bits/stdc++.h"
using namespace std;
int num;
bool ass[50]={0};
int arr[50];
inline void dfs(int a){
	if(a == num+1){
		for(int i = 1;i<=num;++i){
			cout<<setw(5)<<arr[i];
		}
		cout<<endl;
		return;
	}
	for(int i = 1;i<=num;++i){
		if(ass[i]==0){
			ass[i]=1;
			arr[a]=i;
			dfs(a+1);
			ass[i]=0;
		}
	}
	return;
}
int main(void){
	cin>>num;
	dfs(1);
} 

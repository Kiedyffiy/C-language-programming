#include "bits/stdc++.h"
using namespace std;

int n,week;
 struct road{
	int x;
	int y;
	int z;
}w[205],ww[205];
int f[250];
int find(int x){
	if(f[x]!=x){
		f[x]=find(f[x]);
	}
	return f[x];
} 
int t=0;
int result = 0;
bool cmp(road a,road b){
	return a.z<b.z;
} 
int main(void){
	cin>>n>>week;
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	int r1,r2;
	for(int j=1;j<=week;j++){
		cin>>w[t+1].x>>w[t+1].y>>w[t+1].z;
		int r1=find(w[t+1].x);
		int r2=find(w[t+1].y);
		if(r1!=r2){
			f[r2]=r1;
			t++;
			result+=w[t].z;
			ww[t]=w[t];
			sort(w+1,w+t+1,cmp);
			sort(ww+1,ww+t+1,cmp);
		}else{
		  if(w[t+1].z<ww[t].z){
		  for(int i=0;i<=n;i++){
		    f[i]=i;
	      }
	      int k = 0;
	      for(int i=1;i<=t;i++){
	      	if(w[i].z > w[t+1].z){
	      		k = i;
	      		break;
			  }
		  }
		  for(int i=t;i>=k;i--){
		  	swap(w[i+1],w[i]);
		  }
		  int tt =0;
		  result = 0;
		  for(int i=1;i<=t+1;i++){
		  	int r3 = find(w[i].x);
		  	int r4 = find(w[i].y);
		    if(r3!=r4){
		    	f[r3]=r4;
		    	tt++;
		    	result+=w[i].z;
		    	ww[tt]=w[i];	
			}
		  }	
		}
	}
	for(int i=1;i<=t;i++)w[i]=ww[i];
	if(t==n-1){
			cout<<result<<endl;
		}
		else cout<<-1<<endl;
	
	}	
}

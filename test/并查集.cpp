#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
ll dis(ll x1,ll y1,ll z1,ll x2,ll y2,ll z2){
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2);
}
ll fix = 4;
int f[1001];
int a1[10001];//up
int a2[10001];//down
int find(int x){
	if(x!=f[x]){
		f[x] = find(f[x]);
	}
	return f[x];
}
int main(void){
	int num;
	cin>>num;
	int n,h;
	ll r;
	for(int i = 0;i<num;i++){
		cin>>n>>h>>r;
		for(int aa = 0;aa<1001;aa++){
			f[aa]=aa;
		}
		memset(a1,0,sizeof(a1));
		int to1 = 0;
		memset(a2,0,sizeof(a2));
		int to2 = 0;
		ll x[10001] ;
		ll y[10001] ;
		ll z[10001] ;
		for(int j = 0;j<n;j++){
		    cin>>x[j]>>y[j]>>z[j];
		if(h-z[j]<=r){
		   a1[to1]=j;
		   ++to1;
		}
		if(z[j]<=r){
			a2[to2]=j;
			++to2;
		}
		for(int k = 0;k<j;k++){
			if((x[j]-x[k])*(x[j]-x[k])+(y[j]-y[k])*(y[j]-y[k])+(z[j]-z[k])*(z[j]-z[k])>fix*r*r){
				continue; 
			}else{
				//if(dis(x[j],x[k],y[j],y[k],z[j],z[k])<=4*r*r){
					int aj = find(j);
					int ak = find(k);
					if(aj!=ak){
						f[aj]=ak;
					}
				//}
			}
			
		}
		}
		int s = 0;
		for(int p = 0;p<to1;p++){
			for(int q = 0;q<to2;q++){
				if(find(a1[p]) == find(a2[q])){
					s = 1;
					break;
				} 
		    }
		    if(s == 1){
		    	break;
			}
		}
		if(s == 1){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl; 
		}
	}
	
}

 

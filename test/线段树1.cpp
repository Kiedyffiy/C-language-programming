//#include "bits/stdc++.h"//long long!!!!!!
//using namespace std;
//typedef long long ll;
//ll a[1000001],b[1000001],d[1000001],e[1000001] ={0}; 
////lazy dog will set the length of the array to 4n;
//inline void buildtree(int s,int t,int p){//create tree in the section from s to t,point is p
//    if(s == t){// p is the father point;
//    	d[p] = a[s];
//    	return;
//	}
//	int m = s + ((t-s) >> 1);	
//	buildtree(s,m,p*2);
//	buildtree(m+1,t,p*2+1);
//	d[p]=d[p*2]+d[p*2+1];
//}
//inline ll getsum(int l,int r,int s,int t,int p){//[l,r] is the check section;[s,t] is the section of point P;
//	if(l<=s&&r>=t){
//		return d[p];
//	}
//	int m = s + ((t-s)>>1);
//	ll sum = 0;
//	if(e[p] != 0){
//		d[p*2] = e[p]*d[p*2], d[p*2 + 1] = e[p]*d[p*2+1];
//		e[p*2] *= e[p], e[p*2 + 1] *= e[p];
//		e[p] = 0;
//	}
//	if(b[p]){
//		d[p*2] += b[p]*(m - s + 1), d[p*2 + 1] += b[p]*(t - m);
//		b[p*2] += b[p], b[p*2 + 1] += b[p];
//		b[p] = 0;
//	}
//	if(l<=m)sum += getsum(l,r,s,m,p*2);
//	//cout<<sum<<endl;
//	if(r>m)sum += getsum(l,r,m+1,t,p*2+1);
//	//cout<<sum<<endl;
//	return sum;
//}
//inline void update(int l,int r,int c,int s,int t,int p){//c is the adding number
//	if(l<=s&&r>=t){
//		d[p] += (t-s+1)*c,b[p] += c;
//		return;
//	}
//	int m = s + ((t-s)>>1);
//	if((e[p] != 0)&&s!=t){
//		d[p*2] = e[p]*d[p*2], d[p*2 + 1] = e[p]*d[p*2+1];
//		e[p*2] *= e[p], e[p*2 + 1] *= e[p];
//		e[p] = 0;
//	}
//	if((b[p])&&s!=t){
//		d[p*2] += b[p]*(m - s + 1), d[p*2 + 1] += b[p]*(t - m);
//		b[p*2] += b[p], b[p*2 + 1] += b[p];
//		b[p] = 0;
//	}
//	if(l<=m)update(l,r,c,s,m,p*2);
//	if(r>m)update(l,r,c,m+1,t,p*2+1);
//	d[p] = d[p*2]+d[p*2+1];
//}
//inline void update_plus(int l,int r,int c,int s,int t,int p){//c is the adding number
//	if(l<=s&&r>=t){ 
//		d[p] = d[p]*c;
//		if(e[p]==0){
//		e[p] += c;
//		}else{
//		e[p] *= c;
//		}
//		b[p] *= c;
//		return;
//	}
//	int m = s + ((t-s)>>1);
//	if((e[p] != 0)&&s!=t){
//		d[p*2] = e[p]*d[p*2], d[p*2 + 1] = e[p]*d[p*2+1];
//		e[p*2] *= e[p], e[p*2 + 1] *= e[p];
//		e[p] = 0;
//	}
//	if((b[p])&&s!=t){
//		d[p*2] += b[p]*(m - s + 1), d[p*2 + 1] += b[p]*(t - m);
//		b[p*2] += b[p], b[p*2 + 1] += b[p];
//		b[p] = 0;
//	}
//	if(l<=m)update_plus(l,r,c,s,m,p*2);
//	if(r>m)update_plus(l,r,c,m+1,t,p*2+1);
//	d[p] = d[p*2]+d[p*2+1];
//}
//int main(void){
//	std::ios::sync_with_stdio(false);
//    ll l,r,s,t,c,p,pp;
//	int m,n;
//	int fla;
//	int f,g,h;
//	cin	>> n >> m >> pp;
//	for(int i = 1;i<=n;i++){
//		cin>>a[i];
//	}
//	buildtree(1,n,1);
//	for(int i = 1;i<=m;i++){
//		cin>>fla;
//		switch(fla){
//			case 1 :
//				cin>>f>>g>>h;
//				update_plus(f,g,h,1,n,1);
//				break;
//			case 2 :
//				int x,y,z;
//				cin>>x>>y>>z;
//				update(x,y,z,1,n,1);
//				break;
//			case 3 :
//			    int u,o;
//				cin>>u>>o;
//				ll ans = getsum(u,o,1,n,1)%pp;
//				cout<<ans<<endl;
//				break;
//		}	
//	}
//} 
#include "bits/stdc++.h"//long long!!!!!!
using namespace std;
typedef long long ll;
ll l,r,s,t,c,p;
const ll pp = 571373; 
ll a[1000001],b[1000001],d[1000001],e[1000001] ={0}; 
//lazy dog will set the length of the array to 4n;
inline void buildtree(int s,int t,int p){//create tree in the section from s to t,point is p
    if(s == t){// p is the father point;
    	d[p] = a[s];
    	return;
	}
	int m = s + ((t-s) >> 1);	
	buildtree(s,m,p*2);
	buildtree(m+1,t,p*2 + 1);
	d[p]=(d[p*2]+d[p*2 + 1])%pp;
}
inline ll getsum(int l,int r,int s,int t,int p){//[l,r] is the check section;[s,t] is the section of point P;
	if(l<=s&&r>=t){
		return d[p];
	}
	int m = s + ((t-s)>>1);
	ll sum = 0;
	if(e[p] != 0){
		d[p*2] = (e[p]*d[p*2])%pp, d[p*2 + 1] = (e[p]*d[p*2 + 1])%pp;
		e[p*2] = (e[p*2]*e[p])%pp, e[p*2 + 1] = (e[p*2 + 1]*e[p])%pp;
		e[p] = 0;
	}
	if(b[p]){
		d[p*2] = (d[p*2]+b[p]*(m - s + 1))%pp, d[p*2 + 1] = (d[p*2 + 1]+b[p]*(t - m))%pp;
		b[p*2] = (b[p*2]+b[p])%pp, b[p*2 + 1] = (b[p*2 + 1]+b[p])%pp;
		b[p] = 0;
	}
	if(l<=m)sum = (sum + getsum(l,r,s,m,p*2))%pp;
	//cout<<sum<<endl;
	if(r>m)sum = (sum + getsum(l,r,m+1,t,p*2 + 1))%pp;
	//cout<<sum<<endl;
	return sum;
}
inline void update(int l,int r,int c,int s,int t,int p){//c is the adding number
	if(l<=s&&r>=t){
		d[p] = (d[p]+(t-s+1)*c)%pp,b[p] = (b[p]+c)%pp;
		return;
	}
	int m = s + ((t-s)>>1);
	if((e[p] != 0)&&s!=t){
		d[p*2] = (e[p]*d[p*2])%pp, d[p*2 + 1] = (e[p]*d[p*2 + 1])%pp;
		e[p*2] = (e[p*2]*e[p])%pp, e[p*2 + 1] *= (e[p*2 + 1]*e[p])%pp;
		e[p] = 0;
	}
	if((b[p])&&s!=t){
		d[p*2] = (d[p*2]+b[p]*(m - s + 1))%pp, d[p*2 + 1] = (d[p*2 + 1]+b[p]*(t - m))%pp;
		b[p*2] = (b[p*2]+b[p])%pp, b[p*2 + 1] = (b[p*2 + 1]+b[p])%pp;
		b[p] = 0;
	}
	if(l<=m)update(l,r,c,s,m,p*2);
	if(r>m)update(l,r,c,m+1,t,p*2 + 1);
	d[p] = (d[p*2]+d[p*2 + 1])%pp;
}
inline void update_plus(int l,int r,int c,int s,int t,int p){//c is the adding number
	if(l<=s&&r>=t){ 
		d[p] = (d[p]*c)%pp;
		if(e[p]==0){
		e[p] = c%pp;
		}else{
		e[p] = (e[p]*c)%pp;
		}
		b[p] = (b[p]*c)%pp;
		return;
	}
	int m = s + ((t-s)>>1);
	if((e[p] != 0)&&s!=t){
		d[p*2] = (e[p]*d[p*2])%pp, d[p*2 + 1] = (e[p]*d[p*2 + 1])%pp;
		e[p*2] = (e[p*2]*e[p])%pp, e[p*2 + 1] = (e[p*2 + 1]*e[p])%pp;
		e[p] = 0;
	}
	if((b[p])&&s!=t){
		d[p*2] = (d[p*2]+b[p]*(m - s + 1))%pp, d[p*2 + 1] = (d[p*2 + 1]+b[p]*(t - m))%pp;
	b[p*2] = (b[p*2]+b[p])%pp, b[p*2 + 1] = (b[p*2 + 1]+b[p])%pp;
		b[p] = 0;
	}
	if(l<=m)update_plus(l,r,c,s,m,p*2);
	if(r>m)update_plus(l,r,c,m+1,t,p*2 + 1);
	d[p] = (d[p*2]+d[p*2 + 1])%pp;
}
int main(void){
	std::ios::sync_with_stdio(false);
	int m,n;
	int fla;
	int f,g,h;
	int x,y,z;
	ll ff;
	int u,o;
	cin	>> n >> m;
	cin>>ff;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	buildtree(1,n,1);
	for(int i = 1;i<=m;i++){
		cin>>fla;
		switch(fla){
			case 1 :
				cin>>f>>g>>h;
				update_plus(f,g,h,1,n,1);
				break;
			case 2 :
				cin>>x>>y>>z;
				update(x,y,z,1,n,1);
				break;
			case 3 :
				cin>>u>>o;
				ll ans = getsum(u,o,1,n,1)%pp;
				cout<<ans<<endl;
				break;
		}	
	}
	
} 

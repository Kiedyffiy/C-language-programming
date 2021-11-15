#include "bits/stdc++.h"
//lazy dog will set the length of the array to 4n;
void buildtree(int s,int t,int p){//create tree in the section from s to t,point is p
    if(s == t){// p is the father point;
    	d[p] = a[s];
    	return;
	}
	int m = s + ((t-s) >> 1);	
	buildtree(s,m,p*2);
	buildtree(m+1,t,p*2+1);
	d[p]=d[p*2]+d[p*2+1];
}
int getsum(int l,int r,int s,int t,int p){//[l,r] is the check section;[s,t] is the section of point P;
	if(l<=s&&r>=t){
		return d[p];
	}
	int m = s + ((t-s)>>1),sum = 0;
	if(b[p]){
		d[p*2] += b[p]*(m - s + 1), d[p*2 + 1] += b[p]*(t - m);
		b[p*2] += b[p], b[p*2 + 1] += b[p];
		b[p]=0;
	}
	if(l<=m)sum += getsum(l,r,s,m,p*2);
	if(r>m)sum += getsum(l,r,m+1,t,p*2+1);
	return sum;
}
void update(int l,int r,int c,int s,int t,int p){//c is the adding number
	if(l<=s&&r>=t){
		d[p] += (t-s+1)*c,b[p] += c;
		return;
	}
	int m = s + ((t-s)>>1);
	if((b[p])&&s!=t){
		d[p*2] += b[p]*(m - s + 1), d[p*2 + 1] += b[p]*(t - m);
		b[p*2] += b[p], b[p*2 + 1] += b[p];
		b[p] = 0;
	}
	if(l<=m)update(l,r,c,s,m,p*2);
	if(r>m)update(l,r,c,m+1,t,p*2+1);
	d[p] = d[p*2]+d[p*2+1];
}
int main(void){
	
} 

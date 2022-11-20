#include<bits/stdc++.h>
using namespace std;
#define N 1000001
int n;
int a[N];
int maxLeft( int L ,int R){
	int S = 0;
	int ans = a[L];
	for(int i = R ; i>=L;i--){
		S = S+a[i];
		if(ans < S) ans = S;
		
	}
	return ans;
}
int maxRight( int L ,int R){
	int S = 0;
	int ans = a[R];
	for(int i = L ; i<=R;i++){
		S = S+a[i];
		if(ans < S) ans = S;
	}
	return ans;
}
void input(){
	scanf("%d",&n);
	for(int i = 1;i<=n;i++) scanf("%d",&a[i]);
}
int maxSubSeq(int L ,int R){
	if(L==R) return a[L];
	int m = (L+R)/2;
	int wL = maxSubSeq(L,m);
	int wR = maxSubSeq(m+1,R);
	int wLR = maxLeft(L,m)+ maxRight(m+1,R);
	return max(max(wL,wR),wLR);
}
int main(){
	input();
	cout << maxSubSeq(1,n);
	return 0;
}
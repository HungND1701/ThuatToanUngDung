#include<bits/stdc++.h>
using namespace std;
#define N 100

int x[N], n;
bool check(int k, int v){
	if(k==1) return true;
	if(v==1 ) return x[k-1]==0;
	else return true;
}
void solution(){
	for(int i = 1;i<=n;i++){
		cout <<x[i];
	}
	cout << endl;
}
void Try(int k){
	for(int v =0 ;v<=1;v++){
		if(check(k,v)){
			x[k]=v;
			if(k==n) solution();
			else Try(k+1);
		}
	}
}
int main(){
	cin >> n;
	Try(1);
	return 0;
}
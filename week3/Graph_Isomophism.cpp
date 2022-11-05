#include<bits/stdc++.h>
using namespace std;
#define N 20

int n1,m1,n2,m2;
int mt1[N][N], mt2[N][N];
bool ktra = true;
int x[N];
bool xh[N];
bool check(int k , int v){
	return !xh[v];
}
void solution(){
	
	for(int v1 = 1; v1<=n2;v1++){
		for(int v2=1; v2<=n2;v2++){
			if(mt2[x[v1]][x[v2]] != mt1[v1][v2]){
				ktra = false;
				return ;
			}
		}
	}
	ktra = true;
	return;	
}
void Try(int k){	
	for(int v = 1;v<=n2;v++){
		if(check(k,v)){
			x[k]=v;
			xh[v]=true;
			if(k==n2){
				solution();
				if(ktra == true){
					cout << 1;
					return;
				}
			}
			else Try(k+1);
			xh[v] = false;
		}
	}
	
}
int main(){
	cin >> n1 >> m1;
	for(int i=1;i<=m1;i++){
		int v1,v2;
		cin >> v1>>v2;
		mt1[v1][v2] = 1;
		mt1[v2][v1] = 1;
	}
	
	cin >> n2 >> m2;
	for(int i=1;i<=m2;i++){
		int v1,v2;
		cin >> v1>>v2;
		mt2[v1][v2] = 1;
		mt2[v2][v1] = 1;
	}
	for(int i =1; i<=n2;i++){
		xh[i]= false;
	}
	Try(1);
	if(ktra == false) cout << 0;
	return 0;
}
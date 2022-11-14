#include<bits/stdc++.h>
using namespace std;

#define N 50
int n,K;
int d[N];
int Q;
int c[N][N];
int nbSegments ;
bool visited[N];
int y[N],x[N];
int Load[N];
int f; 
int f_min;
int c_min = 0;
void solution(){
	if(f < f_min) f_min = f;
	
}
bool checkX(int v, int i , int k){
	if(v==0) return true;
	
	if(Load[k]+d[v] > Q ) return false;
	if(visited[v] == true) return false;
	 
	return true;
	
}

void TryX(int i,int k){ //Thu gia tri cho x[i] : diem tiep theo tren route[k]
	for(int v = 0; v<=n;v++){
		if(checkX(v,i,k)){
			x[i] = v;
			visited[v] = true;
			Load[k] = Load[k] +d[v];
			f = f + c[i][v];
			nbSegments +=1;
			if(v ==0){
				if(k ==K ){
					if(nbSegments == n+K) solution();
					
				}else if(f + c_min*(n+K-nbSegments) < f_min) TryX(y[k+1],k+1);
			}else{
				if(f + c_min*(n+K-nbSegments) < f_min) TryX(v,k);
			}
			visited[v] = false;
			Load[k] = Load[k] -d[v];
			f = f -c[i][v];
			nbSegments -=1;
		}
	}
}

bool checkY(int v , int k){
	return Load[k] + d[v] <= Q ;
}
void TryY(int k){ // thu gia trij cho y[k]
	for(int v = y[k-1]+1;v<=n-K+k;v++){
		if(checkY(v,k)){
			y[k] = v;
			visited[v] = true;
			Load[k] = Load[k] +d[v];
			f = f + c[0][v];
			nbSegments +=1;
			
			if(k==K) {
				TryX(y[1],1); //start building route[1]
				
			}else TryY(k+1);
			
			visited[v] = false;
			Load[k] = Load[k] -d[v];
			f = f -c[0][v];
			nbSegments -=1;
		}
	}
}


int main(){
	cin >> n >> K >> Q;
	for(int i = 1;i<=n;i++){
		cin >> d[i];
	}
	for(int i = 0 ;i<=n;i++){
		for(int j = 0 ; j<=n;j++){
			
			cin >> c[i][j];
			if(i!=j){
				if(c_min >c[i][j]) c_min = c[i][j];
			}
		}
	}
	
	for(int v = 1 ; v<=n;v++) visited[v] = false;
	for(int k = 1;k<=K ; k++) Load[k] = 0;
	f = 0; f_min= 1e9;
	nbSegments = 0;
	y[0] = 0;
	TryY(1);
	cout << f_min;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define N 1000

int n , d[N][N];
int c[N][N];
void input(){
	cin >> n;
	for(int i = 1; i<=n,i++){
		for(int j =1;j<=n;j++){
			cin >> c[i][j]
		}
	}
}
int selectNearest(int )
void Greedy(int n,int d[][]){
	int current = 1;
	vector<int> route;
	route.push_back(1);
	set<int> C;
	for(int i =2;i<=n;i++) C.insert(i);
	for(int i =2;i<=n;i++){
		int next = selectNearest(current , C)
		C.erase(next);
		route.push_back(next);
		current = next;
		
	}
	route.push_back(1);
	
}
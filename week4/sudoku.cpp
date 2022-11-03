#include<bits/stdc++.h>
using namespace std;
int x[9][9];
bool macdinh[9][9];
int countSolution = 0;
bool markRow[9][10]; //[r][v]
bool markCol[9][10]; //[c][v]
bool markSquare[3][3][10]; //[i][j][v]
bool check(int v , int r , int c){
	return markRow[r][v] == false &&
			markCol[c][v] == false &&
			markSquare[r/3][c/3][v] == false;
			
			
}
void solution(){
	countSolution++ ;
}

void Try(int r , int c){
	if(macdinh[r][c] == true){
		if(r==8 && c==8) solution();
		else {
				if(c<8) Try(r,c+1);
				else Try(r+1,0);
		}
	}
	else{
	
		for(int v = 1;v<=9;v++){
			if(check(v, r, c)){
				x[r][c] = v;
				markRow[r][v] = true;
				markCol[c][v] = true;
				markSquare[r/3][c/3][v] = true;
				if(r==8 && c==8) solution();
				else {
					if(c<8) Try(r,c+1);
					else Try(r+1,0);
				}
				markRow[r][v] = false;
				markCol[c][v] = false;
				markSquare[r/3][c/3][v] = false;
			}
		}
	}
}
int main(){
	for(int i =0;i<=8;i++){
		for(int j = 0;j<=8;j++){
			macdinh[i][j] = false;
		}
	}
	for(int v = 1;v<=9;v++){
		for(int r = 0 ; r<=8;r++){
			markRow[r][v] = false;
		}
		for(int c = 0 ;c<=8;c++){
			markCol[c][v] = false;
		}
		for(int i = 0;i<=2;i++){
			for(int j = 0;j<=2;j++){
				markSquare[i][j][v] = false;
			}
		}
	}
	for(int r= 0;r<=8;r++){
		for(int c = 0; c<=8;c++){
			cin >> x[r][c];
			if(x[r][c] !=0){
				macdinh[r][c] = true;
				markRow[r][x[r][c]] = true;
				markCol[c][x[r][c]] = true;
				markSquare[r/3][c/3][x[r][c]] = true;
			}
		}
	}
	Try(0,0);
	cout << countSolution;
	return 0;
}
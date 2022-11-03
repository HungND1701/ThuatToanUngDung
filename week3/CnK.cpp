#include<iostream>
using namespace std;
#define MAX 999
long long F[MAX][MAX];
long long C(long long k,long long n){
    if(k==0||k==n) F[k][n]=1;
    else{
        if(F[k][n]<0) F[k][n]= (C(k-1,n-1)+C(k,n-1))%(long long)(1E9 + 7);
    }
    return F[k][n];
}
int main(){
    long long n,k;
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++) F[i][j]=-1;
    }
    cin >> k >> n;
   	cout << C(k,n);

    return 0;
}
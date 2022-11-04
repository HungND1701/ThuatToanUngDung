#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	int n, m;
	
	cin >> T;
	for(int i = 1; i <= T ; i++){
		cin >> n >> m;
		int arr1[n];
		int arr2[m];
		if(n!=m) {
			for(int j = 0; j <n ; j++){
				cin >> arr1[j];
			}
			for(int j = 0; j <m ; j++){
				cin >> arr2[j];
			}
			cout << 0 << endl;
		}
		else{
			bool ktra = true;
			for(int j = 0; j <n ; j++){
				cin >> arr1[j];
			}
			for(int j = 0; j <n ; j++){
				cin >> arr2[j];
			}
			for(int j = 0; j <n ; j++){
				if(arr1[j]!=arr2[j]){
					ktra = false;
					break;
				}	
			}
			cout << (ktra == true ? 1:0) << endl;
		}
	}
}
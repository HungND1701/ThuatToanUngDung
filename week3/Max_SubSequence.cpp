#include<bits/stdc++.h>
#define MAX 1000000
#define oo -(1e9+6)
using namespace std;
int arr[MAX],n;
int maxsub(){

    int sum_max,s[n];
    sum_max=arr[0];
    s[0]=arr[0];
    for(int i=1;i<n;i++){
        if(s[i-1]>0) s[i]=s[i-1]+arr[i];
        else s[i]=arr[i];
        if(sum_max<s[i]) sum_max=s[i];
    }    
    return sum_max;
}
int main(){

    cin >> n;
    
    for(int i=0 ; i<n; i++){
        cin >> arr[i];
    }
    cout << maxsub();
    return 0;
} 
#include<iostream>
#include<cmath>
#include<limits>
#include"checkBitSet.cpp"
#include"countSetBits.cpp"
using namespace std;

int assignment(int arr[][3], int n){
    int a,b,l=pow(2,n);
    int dp[l];
    for(int i=0;i<l;i++)
        dp[i]=INT_MAX;
    dp[0]=0;
    for(int i=0;i<l;i++){
        for(int j=0;j<n;j++){
            if(!checkBitSet(i,j)){
                a=dp[i|(1<<j)];
                b=dp[i]+arr[countSetBits(i)][j];
                dp[i|(1<<j)]=(a<b)?a:b;
            }
        }
    }
    return dp[l-1];
}
int main(){
    int arr[3][3];
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            cin>>arr[i][j];
    cout<<(assignment(arr,3));
}

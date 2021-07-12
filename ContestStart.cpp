#include<iostream>
using namespace std;
int main(){
    int c;
    cin>>c;
    while(c--){
        long long int n,x,t;
        long long int sd=0;
        cin>>n>>x>>t;
        long long int i=t/x;
        sd=i*(n-i-1);
        for(;i>0;i--)
            sd+=i;
        cout<<sd;
    }
}

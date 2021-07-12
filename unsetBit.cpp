#include<iostream>
using namespace std;
int main(){
    int n,b;
    cin>>n>>b;
    n&=~(1<<b);
    cout<<n;
}

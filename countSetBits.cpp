#include<iostream>
using namespace std;

int countSetBits(int n){
    int c=0;
    while(n!=0){
        if(n&1!=0)c++;
        n>>=1;
    }
    return c;
}

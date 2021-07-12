#include<iostream>
using namespace std;
int checkBitSet(int n, int b){
    n>>=b;
    return(int)(n&1);
}

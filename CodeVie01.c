#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    long long int a=LONG_MIN,b=LONG_MIN,j;
    bool f=false;
    int c=0;
    long long int n;
    scanf("%lld",&n);
    for(long long int i=0;i<n;i++){
        scanf("%lld",&j);
        if(j>a){
            b=a;
            a=j;
            if(c++==1)
                f=true;
        }
        else if(j>b&&j!=a){
            b=j;
            f=true;
        }
    }
    if(f)
        printf("%lld",b);
    else
        printf("%d",-1);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL pre[100005];
int main()
{
    LL n,i,j,flag=0,x;
    cin >> n;
    for(i=1; i<=n; i++)
    {
        cin >> x;
        // store pre[i]= sum of all elements till index i.
        pre[i]=pre[i-1]+x;
    }
    for(i=1; i<=n; i++)
    {
        // check if sum to left is same as sum to right
        if(pre[i-1]==(pre[n]-pre[i]))flag=1;
    }
    if(flag)cout << "YES\n";
    else cout << "NO\n";
    return 0;
}

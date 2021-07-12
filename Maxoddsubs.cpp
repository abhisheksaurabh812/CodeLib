#include <iostream>
#include<string>
using namespace std;
class Solution {
public:
    string largestOddNumber(string num) {
        string maxodd="";
        for(int i=1;i<=num.length();i++){
            for(int j=0;j<=num.length()-i;j++){
                int k=i+j-1;
                string s=num.substr(i, k-i);
                if((int)(s.at(s.length()-1))%2==0){
                    if(s.length()>maxodd.length()){
                        maxodd=s;
                    }
                    else if(s.length()!=0 && s.length()==maxodd.length()){
                        for(int k=0;k<s.length();k++){
                            if ((maxodd.at(k) - '0') < (s.at(k) - '0'))
                            {
                                maxodd=s;
                                break;
                            }
                        }
                    }
                }
            }
        }
        return maxodd;
    }
};
int main(){
        string num;
        cin>>num;
        Solution s;
        cout<<s.largestOddNumber(num);
        return 0;
    }

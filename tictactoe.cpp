#include <iostream>
using namespace std;

int check(char a, char b, char c, char d){
    if(a==d&&a==b&&a==c)
        return 1;
    else
        return 0;
}

int nextWin(char arr[3][3], int n, char ch){
    switch(n){
        case 0: if(check(arr[0][0],arr[0][1],arr[0][2],ch))
                return 1;
        case 1: if(check(arr[1][0],arr[1][1],arr[1][2],ch))
                return 2;
        case 2: if(check(arr[2][0],arr[2][1],arr[2][2],ch))
                return 3;
        case 3: if(check(arr[0][0],arr[1][0],arr[2][0],ch))
                return 4;
        case 4: if(check(arr[0][1],arr[1][1],arr[2][1],ch))
                return 5;
        case 5: if(check(arr[0][2],arr[1][2],arr[2][2],ch))
                return 6;
        case 6: if(check(arr[0][0],arr[1][1],arr[2][2],ch))
                return 7;
        case 7: if(check(arr[0][2],arr[1][1],arr[2][0],ch))
                return 8;
        default: return -1;
    }
}

int checkWin(char arr[3][3]){
    int w=0,wcx=0,wco=0,wx=0,wo=0;
    char ch='X';
    do{
        if(ch=='X'){
            if(w==1)
                return 3;
            wx=nextWin(arr,wx,ch);
            if(wx!=-1){
                wcx++;
                w=1;
            }
        }
        else{
            if(w==1||w==2)
                return 3;
            wo=nextWin(arr,wo,ch);
            if(wx!=-1){
                wco++;
                w=2;
            }
        }
        if(ch=='X')
            ch='O';
        else
            ch='X';
        //cout<<ch<<" "<<wx<<" "<<wo<<endl;
    }while(wx==-1&&wo==-1);
    return w;
}

int main() {
	// your code goes here
	long long int t;
	cin>>t;
	char arr[3][3];
	while(t--){
	    for(int i=0;i<3;i++)
	        for(int j=0;j<3;j++)
	            cin>>arr[i][j];
	    int no=0,nx=0,result;
	    for(int i=0;i<3;i++){
	        for(int j=0;j<3;j++){
	            if(arr[i][j]=='X')
	                nx++;
	            else if(arr[i][j]=='O')
	                no++;
	        }
	    }
	    //cout<<checkWin(arr)<<endl;
	    if(!((no==nx)||((nx-no)==1)))
	        result=3;
	    else{
	        if(((no+nx)!=9)&&checkWin(arr)==0&&((no==nx)||((nx-no)==1)))
	            result=2;
	        else if((checkWin(arr)==1&&((nx-no)==1))||(checkWin(arr)==2&&(nx==no)))
	            result=1;
	        else
	            result=3;
	    }
	    cout<<result<<endl;
	}
	return 0;
}

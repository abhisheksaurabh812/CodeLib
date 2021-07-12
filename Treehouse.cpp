#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void addEdge(vector<int> g[], int u, int v){
    g[u].push_back(v);
    g[v].push_back(u);
}

void mySort(vector<int>& v1, vector<int>& v2){
    int i,j,t;
    for(i=0;i<v1.size()-1;i++){
        for(j=0;j<v1.size()-i-1;j++){
            if(v2[j]>v2[j+1]){
                t=v1[j];
                v1[j]=v1[j+1];
                v1[j+1]=t;
                t=v2[j];
                v2[j]=v2[j+1];
                v2[j+1]=t;
            }
        }
    }
}

void merge(vector<int>& arr, vector<int>& arr2, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int L[n1], R[n2], L2[n1], R2[n2];


    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++){
        L[i] = arr[l + i];
        L2[i] = arr2[l+i];
    }
    for (int j = 0; j < n2; j++){
        R[j] = arr[m + 1 + j];
        R2[j] = arr2[m+1+j];
    }
    // Merge the temp arrays back into arr[l..r]

    // Initial index of first subarray
    int i = 0;

    // Initial index of second subarray
    int j = 0;

    // Initial index of merged subarray
    int k = l;

    while (i < n1 && j < n2) {
        if (L2[i] <= R2[j]) {
            arr[k] = L[i];
            arr2[k] = L2[i];
            i++;
        }
        else {
            arr[k] = R[j];
            arr2[k] = R2[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        arr2[k] = L2[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        arr2[k] = R2[j];
        j++;
        k++;
    }
}
void mergeSort(vector<int>& arr, vector<int>& arr2, int l,int r){
    if(l>=r){
        return;//returns recursively
    }
    int m =l+ (r-l)/2;
    mergeSort(arr,arr2,l,m);
    mergeSort(arr,arr2,m+1,r);
    merge(arr,arr2,l,m,r);
}

int getChildSum(vector<int> g[], vector<int>& val, vector<int>& vis, int n, int p){
    int sum=0;
    if(g[n][0]!=1||g[n].size()>1)
    for(int i=0;i<g[n].size();i++){
        if(g[n][i]!=p)
            sum+=val[g[n][i]]+getChildSum(g,val,vis,g[n][i],n);
    }
}

int getValue(vector<int> g[],vector<int>& summ, vector<int>& val, vector<int>& vis, int n, int v){
    cout<<n<<endl;
    cout<<"val arr : ";
	    for(int i=0;i<val.size();i++)
            cout<<i<<" "<<val[i]<<"   ";
        cout<<endl;
    if(g[n].size()>1||n==0){
        vis[n]=1;
        vector<int> arr(g[n].size(),-1);
        for(int i=0;i<g[n].size();i++){
            if(vis[g[n][i]]==1)
                arr[i]=0;
            else
                arr[i]=getValue(g,summ,val,vis,g[n][i],v);
        }
        cout<<"Before sort : ";
        for(int i=0;i<g[n].size();i++)
            cout<<g[n][i]<<" "<<arr[i]<<"   ";
        cout<<endl;
        mergeSort(g[n],arr,0,arr.size()-1);
        cout<<"After sort : ";
        for(int i=0;i<arr.size();i++)
            cout<<g[n][i]<<" "<<arr[i]<<"   ";
        cout<<endl;
        long long int sum=0;
        for(int i=0,c=1;i<g[n].size();i++){
            if(arr[i]!=0){
                if(arr[0]==0)
                    val[g[n][i]]=v*(arr.size()-c);
                else
                    val[g[n][i]]=v*(arr.size()-i);
                summ[g[n][i]]=val[g[n][i]]/v*(1+getChildSum(g,val,vis,g[n][i],n));
                sum+=summ[g[n][i]];
                c++;
            }
        }
        cout<<"val arr : ";
	    for(int i=0;i<summ.size();i++)
            cout<<i<<" "<<summ[i]<<"   ";
        cout<<endl;
        return sum+v;
    }
    cout<<"val arr : ";
    for(int i=0;i<val.size();i++)
        cout<<i<<" "<<val[i]<<"   ";
    cout<<endl;
    vis[n]=1;
    return v;
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    long long int n,x,u,v;
	    cin>>n>>x;
	    vector<int> g[n];
	    vector<int> vis(n,0);
	    vector<int> val(n,0);
	    vector<int> sum(n,0);
	    for(int i=1;i<n;i++){
	        cin>>u>>v;
	        addEdge(g,u-1,v-1);
	    }
	    getValue(g,sum,val,vis,0,x);
	    for(int i=1;i<val.size();i++)
            x+=val[i];
	    cout<<x%1000000007<<endl;
	}
	return 0;
}

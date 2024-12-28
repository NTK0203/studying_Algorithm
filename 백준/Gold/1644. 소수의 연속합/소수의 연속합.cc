#include <iostream>
#include <vector>
using namespace std;

vector<int> primenum;

void Setprimenumber(int n){
    vector<int> arr(n+1);
    for(int i=2; i<=n;i++)
        arr[i]=i;
    for(int i=2;i*i<=n;i++){
        if(arr[i]==0)
            continue;
        for(int j=i*i;j<=n;j+=i)
            arr[j]=0;
    }
    for(int i=2;i<=n;i++)
        if(arr[i]!=0)
            primenum.push_back(arr[i]);
}

int Sumprimenumber(int n){
    int l=0,r=0,count=0;
    while(l<primenum.size()&&r<primenum.size()){
        int total=0;
        for(int i=l;i<=r;i++)
            total+=primenum[i];
        if(total==n){
            count++;
            if(l<r)
                l++;
            else
                r++;
        }
        else if(total<n)
            r++;
        else
            if(l<r)
                l++;
            else
                r++;
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    Setprimenumber(n);
    cout<<Sumprimenumber(n);
}
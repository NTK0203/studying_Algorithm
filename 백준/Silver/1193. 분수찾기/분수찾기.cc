#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt=1,sum=0,x;
    cin>>x;
    while(sum<x){
        sum+=cnt++;
    }
    cnt--; //2 3 
    int idx=x-(sum-cnt)-1;
    if(cnt%2==0)
        cout<<1+idx<<"/"<<cnt-idx;
    else
       cout<<cnt-idx<<"/"<<1+idx;
}
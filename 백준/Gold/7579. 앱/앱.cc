#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int dp[10001], memory[101], cost[101], minimum=INT_MAX, costsum=0;
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<2;i++)
        for(int j=0;j<n;j++){
            int input;
            cin>>input;
            if(i==0)
                memory[j]=input;
            else{
                cost[j]=input;
                costsum+=input;
            }
        }
    for(int i=0;i<n;i++){
        for(int j=costsum;j>=cost[i];j--){
            dp[j]=max(dp[j],dp[j-cost[i]]+memory[i]);
            if(dp[j]>=m)
                minimum=min(minimum,j);
        }
    }
    cout<<minimum;
}
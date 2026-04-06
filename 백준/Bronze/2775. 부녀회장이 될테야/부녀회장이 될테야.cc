#include <iostream>
using namespace std;

int main(){
    int t;
    int dp[15][15]={0,};
    for(int i=0;i<15;i++){
        dp[0][i]=i;
    }
    for(int i=1;i<15;i++){
        for(int j=0;j<15;j++){
            for(int k=0;k<=j;k++){
                dp[i][j]+=dp[i-1][k];
            }
        }
    }
    cin>>t;
    for(int i=0;i<t;i++){
        int k,n,total=0;
        cin>>k>>n;
        cout<<dp[k][n]<<"\n";
    }
}
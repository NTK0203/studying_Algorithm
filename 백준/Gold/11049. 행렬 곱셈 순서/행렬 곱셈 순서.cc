#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int n, arr[501][2], dp[501][501];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i][0]>>arr[i][1];
    
    for(int i=1;i<n;i++)
        for(int j=1;j+i<=n;j++){
            dp[j][i+j]=INT_MAX;
            for(int k=j;k<=i+j;k++)
                dp[j][i+j]=min(dp[j][i+j],dp[j][k]+dp[k+1][j+i]+arr[j][0]*arr[k][1]*arr[j+i][1]);
        }
    cout<<dp[1][n];
}
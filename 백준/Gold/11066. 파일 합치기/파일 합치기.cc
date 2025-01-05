#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int t,k, dp[501][501],sum[501];
vector<int> arr;

int main(){
    cin>>t;
    while(t-->0){
        cin>>k;
        arr.push_back(0);
        for(int i=0;i<k;i++){
            int c;
            cin>>c;
            arr.push_back(c);
        }
                
        for(int i=1;i<=k;i++)
            sum[i]=sum[i-1]+arr[i];
        

        for(int i=1;i<k;i++)
            for(int j=1;j+i<=k;j++){
                dp[j][i+j]=INT_MAX;
                for(int l=j;l<j+i;l++){
                    dp[j][i+j]=min(dp[j][i+j],dp[j][l]+dp[l+1][i+j]+sum[i+j]-sum[j-1]);
                }
            }
        cout<<dp[1][k]<<"\n";
        arr.clear();
    }
}
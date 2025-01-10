#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000001
using namespace std;

int n, result=MAX;
vector<vector<int>> arr;

int main(){
    cin>>n;
    arr.resize(n);
    int input;
    for(int i=0;i<n;i++)
        for(int j=0;j<3;j++){
            cin>>input;
            arr[i].push_back(input);
        }

    for(int i=0;i<3;i++){
        int dp[1000][3];
        for(int j=0;j<3;j++){
            if(j==i)
                dp[0][j]=arr[0][j];
            else
                dp[0][j]=MAX;
        }
        for(int j=1;j<n;j++){
            dp[j][0]=min(dp[j-1][1],dp[j-1][2])+arr[j][0];
            dp[j][1]=min(dp[j-1][0],dp[j-1][2])+arr[j][1];
            dp[j][2]=min(dp[j-1][0],dp[j-1][1])+arr[j][2];
        }
        for(int j=0;j<3;j++){
            if(j==i)
                continue;
            result=min(result,dp[n-1][j]);
        }
    }
    cout<<result;
}
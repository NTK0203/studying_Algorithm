#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, max=0;
    vector<int> arr, dp;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
        dp.push_back(a);
        if(a>=max)
            max=a;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                if(dp[i]<dp[j]+arr[i]){
                    dp[i]=dp[j]+arr[i];
                    if(dp[i]>=max)
                        max=dp[i];
                }
            }
        }
    }
    cout<<max;
}
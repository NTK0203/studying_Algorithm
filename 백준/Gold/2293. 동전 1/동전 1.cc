#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> coin;
    int dp[10001]={0,};
    dp[0]=1;
    int n, k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int c;
        cin>>c;
        coin.push_back(c);
    }
    for(auto p : coin){
        for(int i=1;i<=k;i++){
            if(i-p>=0){
                dp[i]+=dp[i-p];
            }
        }
    }
    cout<<dp[k];
}
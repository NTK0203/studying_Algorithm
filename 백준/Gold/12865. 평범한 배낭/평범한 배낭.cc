#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n,k;
    int dp[100001];
    fill(dp,dp+100001,0);
    vector<pair<int,int>> item;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int w,v;
        cin>>w>>v;
        item.push_back({w,v});
    }
    for(auto p : item){
        int w=p.first, v=p.second;
        for(int i=k;i>0;i--){
            if(i-w>=0)
                dp[i]=max(dp[i], dp[i-w]+v);
        }
    }
    cout<<dp[k];
}
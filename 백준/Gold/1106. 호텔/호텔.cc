#include <iostream>
#include <vector>
using namespace std;
#define INF 999999999

int main(){
    int c, n, result=INF;
    vector<pair<int,int>> city;
    int dp[1101];
    dp[0]=0;
    for(int i=1;i<1101;i++)
        dp[i]= INF;
    
    cin>>c>>n;
    for(int i=0;i<n;i++){
        int cost, customer;
        cin>>cost>>customer;
        city.push_back({cost, customer});
    }
    for(int i=1;i<1101;i++){
        for(int j=0;j<city.size();j++){
            int cost=city[j].first, customer=city[j].second;
            if(i-customer>=0)
                dp[i]=min(dp[i], dp[i-customer]+cost);
        }
        if(result>dp[i] && i>=c)
            result=dp[i];
    }
    cout<<result;
}
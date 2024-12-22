#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int t,n,k,w;
vector<int> d, dp, indegree;
vector<vector<int>> order;

int main(){
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>k;
        d.resize(n+1);
        dp.resize(n+1);
        order.resize(n+1);
        indegree.resize(n+1);

        for(int j=1;j<=n;j++)
            cin>>d[j];

        for(int j=1;j<=k;j++){
            int x,y;
            cin>>x>>y;
            order[x].push_back(y);
            indegree[y]++;
        }
        queue<int> q;
        
        for(int j=1;j<=n;j++){
            if(indegree[j]==0){
                q.push(j);
                dp[j]=d[j];
            }
        }
        while(!q.empty()){
            int v=q.front();
            q.pop();
            for(int j=0;j<order[v].size();j++){
                int v2=order[v][j];
                if(v2>0){
                    dp[v2]=max(dp[v2],dp[v]+d[v2]);
                    indegree[v2]--;
                    if(indegree[v2]==0)
                        q.push(v2);
                }
            }
        }
        cin>>w;
        cout<<dp[w]<<"\n";
        dp.clear();
        d.clear();
        order.clear();
        indegree.clear();
    }
}
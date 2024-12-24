#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n,m;
vector<vector<int>> v;
vector<int> indegree;
int main(){
    cin>>n>>m;
    v.resize(n+1);
    indegree.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        indegree[b]++;
        v[a].push_back(b);
    }
    queue<int> q;
    for(int i=1;i<=n;i++)
        if(indegree[i]==0)
            q.push(i);
    
    while(!q.empty()){
        int v1=q.front();
        q.pop();
        cout<<v1<<" ";
        for(int i=0;i<v[v1].size();i++){
            int v2=v[v1][i];
            if(v2>0)
                if(--indegree[v2]==0)
                    q.push(v2);
        }
    }
}
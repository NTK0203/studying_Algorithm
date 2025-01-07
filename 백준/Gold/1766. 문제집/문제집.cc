#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,m;
vector<int> indegree;
vector<vector<int>> v;
priority_queue<int, vector<int>, greater<int>> q;

int main(){
    cin>>n>>m;
    indegree.resize(n+1);
    v.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        indegree[b]++;
        v[a].push_back(b);
    }

    for(int i=1;i<=n;i++)
        if(indegree[i]==0)
            q.push(i);
    while(!q.empty()){
        int v1=q.top();
        q.pop();
        for(int i=0;i<v[v1].size();i++){
            int v2=v[v1][i];
            if(v2>0)
                if(--indegree[v2]==0)
                    q.push(v2);
        }
        cout<<v1<<" ";
    }
}
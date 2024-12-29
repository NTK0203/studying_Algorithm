#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> indegree;
vector<vector<int>> v;
queue<int> q, result;

int main(){
    int n,m;
    cin>>n>>m;
    indegree.resize(n+1);
    v.resize(n+1);
    for(int i=0;i<m;i++){
        int order;
        cin>>order;
        int f,b;
        cin>>f;
        for(int j=0;j<order-1;j++){
            cin>>b;
            indegree[b]++;
            v[f].push_back(b);
            f=b;
        }
    }
    for(int i=1;i<=n;i++)
        if(indegree[i]==0)
            q.push(i);
    while(!q.empty()){
        int v1=q.front();
        result.push(v1);
        q.pop();
        for(int i=0;i<v[v1].size();i++){
            int v2=v[v1][i];
            if(v2>0)
                if(--indegree[v2]==0)
                    q.push(v2);
            }
    }
    if(result.empty())
        cout<<"0";
    else if(result.size()!=n)
        cout<<"0";
    else
        for(int i=0;i<n;i++){
            cout<<result.front()<<"\n";
            result.pop();
        }
}
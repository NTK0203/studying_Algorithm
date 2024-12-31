#include <iostream>
#include <vector>

using namespace std;

int t,n,count;
vector<int> graph;
vector<bool> visited, recstack;

void dfs(int node){
    int next=graph[node];
    visited[node]=true;

    if(!visited[next])
        dfs(next);
    else if(!recstack[next]){
        while(next!=node){
            count++;
            next=graph[next];
        }
        count++;
    }
    recstack[node]=true;
}

int main(){
    cin>>t;
    for(int i=0;i<t;i++){
        count=0;
        cin>>n;
        graph.resize(n+1);
        visited.resize(n+1);
        recstack.resize(n+1);
        for(int j=1;j<=n;j++){
            cin>>graph[j];
            visited[j]=false;
            recstack[j]=false;
        }
        for(int j=1;j<=n;j++)
            if(!visited[j])
                dfs(j);
        
        cout<<n-count<<"\n";
        graph.clear();
        visited.clear();
        recstack.clear();
    }
}
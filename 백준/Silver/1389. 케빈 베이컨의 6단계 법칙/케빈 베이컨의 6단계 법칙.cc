#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define INF 99999999

int arr[101][101];
int sum[101][101];
int n,m;

void bfs(){
    for(int i=1;i<=n;i++){
        queue<pair<int,int>> q;
        bool visited[101];
        memset(visited,false,sizeof(visited));
        q.push({i,1});
        visited[i]=true;
        while(!q.empty()){
            pair<int,int> cur = q.front();
            q.pop();
            int v=cur.first, cnt=cur.second;
            for(int j=1;j<=n;j++){
                if(j==v)
                    continue;
                if(!visited[j] && arr[v][j]==1){
                    visited[j]=true;
                    sum[i][j]=cnt;
                    sum[j][i]=cnt;
                    q.push({j,cnt+1});
                }
            }
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            arr[i][j]=INF;
            sum[i][j]=INF;
        }
    for(int i=1;i<=n;i++){
        arr[i][i]=0;
        sum[i][i]=0;
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        arr[a][b]=1;
        arr[b][a]=1;
        sum[a][b]=1;
        sum[b][a]=1;
    }
    bfs();
    int minimum=INF, idx;
    for(int i=1;i<=n;i++){
        int s=0;
        for(int j=1;j<=n;j++)
            s+=sum[i][j];
        if(minimum>s){
            minimum=s;
            idx=i;
        }
    }
    cout<<idx;
}
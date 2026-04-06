#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int arr[100][100];
int n,m;
int dx[4]={0,0,-1,1}, dy[4]={-1,1,0,0};

bool dfs(int x, int y){
    bool visited[100][100]={false,}, ret=false;
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y]=true;
    while(!q.empty()){
        int cx=q.front().first, cy=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=cx+dx[i], ny=cy+dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=m)
                continue;
            if(!visited[nx][ny]){
                if(arr[nx][ny]==0){
                    visited[nx][ny]=true;
                    q.push({nx,ny});
                }
                else{
                    if(++arr[nx][ny]==3)
                        ret=true;
                }
            }
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>arr[i][j];

    bool ret=true;
    int result=0;

    while(ret){
        ret=dfs(0,0);
        if(!ret)
            break;
        result++;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                if(arr[i][j]>1){
                    if(arr[i][j]==2)
                        arr[i][j]=1;
                    else{
                        arr[i][j]=0;
                    }
                }
            }
    }
    cout<<result;
}
#include <iostream>
#include <algorithm>
using namespace std;
int arr[500][500]={0,}, dp[500][500];
int dx[4]={0,0,-1,1}, dy[4]={1,-1,0,0},m ,n;

int dfs(int x, int y){
    if(x==m-1 && y==n-1)
        return 1;
    else if(dp[x][y]!=-1)
        return dp[x][y];
    dp[x][y]=0;
    for(int i=0;i<4;i++){
        int nx=x+dx[i], ny=y+dy[i];
        if(nx<0 || nx>=m || ny<0 || ny>=n)
            continue;
        if(arr[x][y]>arr[nx][ny])
            dp[x][y]+=dfs(nx, ny);
    }
    return dp[x][y];
}

int main(){
    cin>>m>>n;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
            dp[i][j]=-1;
        }
        
    cout<<dfs(0,0);
}
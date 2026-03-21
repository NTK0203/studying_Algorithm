#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

struct robot{
    int x;
    int y;
    int dir; //0: N, 1: E, 2: S, 3: W
};

int main(){
    int n, m;
    int arr[50][50];
    bool visited[50][50];
    struct robot r;
    queue<robot> q;
    memset(visited, false, sizeof(visited));
    cin>>n>>m>>r.x>>r.y>>r.dir;

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>arr[i][j];
    
    q.push(r);
    while(!q.empty()){
        robot cur_r = q.front();
        q.pop();
        int x=cur_r.x, y=cur_r.y;
        int dir=cur_r.dir;

        if(visited[x][y]==false)
            visited[x][y]=true;
        
        bool has_empty=false;

        for(int i=1;i<=4;i++){
            int ndir=(4+(dir-i))%4;
            int nx=x+dx[ndir], ny=y+dy[ndir];
            if(nx<0 || nx>=n || ny<0 || ny>=m)
                continue;
            if(!has_empty && !visited[nx][ny]){
                if(arr[nx][ny]==0){
                    robot next_r={nx,ny,ndir};
                    q.push(next_r);
                    has_empty=true;
                    break;
                }
            }
        }

        if(!has_empty){
            int back_dir=(dir+2)%4;
            int back_x=x+dx[back_dir], back_y=y+dy[back_dir];
            if(back_x<0 || back_x>=n || back_y<0 || back_y>=m || arr[back_x][back_y]==1)
                break;
            robot back_r={back_x,back_y,dir};
            q.push(back_r);
        }
    }

    int cnt=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(visited[i][j])
                cnt++;
    cout<<cnt;
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

pair<int,int> loc;
int n, arr[20][20], scale=2, sizeup=0, result=0;
int dx[4]={0,0,-1,1}, dy[4]={-1,1,0,0}, fish[7]={0,};

//return: 먹은 생선 크기, -1이라면 더이상 먹을 생선이 없음.
int bfs(int x, int y){
    queue<pair<int,int>> q;
    vector<pair<int,int>> v;
    int dist[20][20], stop_dist=999;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            dist[i][j]=-1;
    q.push({x,y});
    dist[x][y]=0;
    while(!q.empty()){
        int cx=q.front().first, cy=q.front().second;
        q.pop();
        if(dist[cx][cy] == stop_dist)
            continue;
        for(int i=0;i<4;i++){
            int nx=cx+dx[i], ny=cy+dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=n)
                continue;
            if(dist[nx][ny]==-1){
                if(arr[nx][ny]==0 || arr[nx][ny]==scale){
                    q.push({nx,ny});
                    dist[nx][ny]=dist[cx][cy]+1;
                }
                else if(arr[nx][ny]<scale){
                    dist[nx][ny]=dist[cx][cy]+1;
                    if(stop_dist==999)
                        stop_dist=dist[nx][ny];
                    v.push_back({nx,ny});
                }
            }
        }
    }
    if(v.empty())
        return -1;

    pair<int,int> max_loc={n-1,n-1};
    for(auto p : v)
        if(p.first<max_loc.first || (p.first==max_loc.first && p.second<max_loc.second))
            max_loc={p.first,p.second};
    int rx=max_loc.first, ry=max_loc.second, ate_fish=arr[rx][ry];
    result+=dist[rx][ry];

    loc.first=rx;
    loc.second=ry;

    arr[rx][ry]=0;

    return ate_fish;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
            if(arr[i][j]==9){
                loc={i,j};
                arr[i][j]=0;
            }
            else if(arr[i][j]!=0)
                fish[arr[i][j]]++;
            
        }
    int ate_fish=0;
    while(ate_fish != -1){
        ate_fish=bfs(loc.first, loc.second);
        sizeup++;
        if(sizeup==scale){
            sizeup=0;
            scale++;
        }
    }
    cout<<result;
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, l, r;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int arr[50][50];
bool visited[50][50];
vector<pair<int,int>> unions;

bool bfs(){
    bool is_imigrated=false;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            visited[i][j]=false;
    
    unions.clear();

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j]){
                unions.clear();
                queue<pair<int,int>> q;

                q.push({i,j});
                unions.push_back({i,j});
                visited[i][j]=true;
                int s=arr[i][j];

                while(!q.empty()){
                    int x=q.front().first, y=q.front().second;
                    q.pop();
                    
                    for(int k=0;k<4;k++){
                        int nx=x+dx[k], ny=y+dy[k];
                        if(nx<0 || nx>=n || ny<0 || ny>=n)
                            continue;
                        
                        if(!visited[nx][ny]){
                            int diff=abs(arr[x][y]-arr[nx][ny]);

                            if(diff>=l && diff<=r){
                                visited[nx][ny]=true;
                                unions.push_back({nx,ny});
                                q.push({nx,ny});
                                s+=arr[nx][ny];
                            }
                        }
                    }
                }
                if(unions.size()!=1){
                    int population=int(s/unions.size());
                    for(auto p : unions)
                        arr[p.first][p.second]=population;
                    is_imigrated=true;
                }
            }
        }
    }
    return is_imigrated;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>l>>r;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    int cnt=0;
    while(1){
        if(!bfs()){
            break;
        }
        cnt++;
    }
    cout<<cnt;
}
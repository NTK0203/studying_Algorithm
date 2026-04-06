#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

struct status{
    int x;
    int y;
    int key;
    int dist;
};

int dfs(int n, int m, vector<char> arr[], status s){
    bool visited[50][50][64];
    memset(visited, false, sizeof(visited));
    queue<status> q;
    q.push(s);
    while(!q.empty()){
        status cur_s=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            status next_s=cur_s;
            int nx=cur_s.x+dx[i], ny=cur_s.y+dy[i];
            int nkey=next_s.key;
            next_s.x=nx;
            next_s.y=ny;
            
            if(nx<0 || nx>=n || ny<0 || ny>=m)
                continue;

            if(arr[nx][ny]=='1')
                return next_s.dist+1;
            else if(arr[nx][ny]=='#')
                continue;
            else if(!visited[nx][ny][nkey]){
                if('a'<=arr[nx][ny] && arr[nx][ny]<='f'){
                    visited[nx][ny][nkey]=true;
                    nkey|=1<<arr[nx][ny]-'a';
                    next_s.key=nkey;
                    next_s.dist++;
                    q.push(next_s);
                    continue;
                }
                else if('A'<=arr[nx][ny] && arr[nx][ny]<='F')
                    if((nkey & (1<<(arr[nx][ny]-'A'))) == 0)
                        continue;
                next_s.dist++;
                q.push(next_s);
                visited[nx][ny][nkey]=true;
            }
        }
    }
    return -1;
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<char> arr[n];
    pair<int, int> cur_loc;
    
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<m;j++){
            arr[i].push_back(s[j]);
            if(s[j]=='0')
                cur_loc={i,j};
        }
    }
    status s={cur_loc.first, cur_loc.second, 0, 0};
    cout<<dfs(n,m,arr,s);
}
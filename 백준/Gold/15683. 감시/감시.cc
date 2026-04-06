#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define NON -1
#define UP 0
#define DOWN 1
#define RIGHT 2
#define LEFT 3

int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};

int n, m, mini=999999;
int arr[8][8]; //0은 빈공간, 1~5 cctv, 6은 벽, -1은 5번에 의해 이미 칠해진 영역
vector<pair<int,int>> cctv;
int visited[8][8]={0,};
vector<vector<vector<int>>> state={
    {},
    {{LEFT},{UP},{RIGHT},{DOWN}},
    {{LEFT,RIGHT},{UP,DOWN}},
    {{UP,RIGHT},{RIGHT,DOWN},{DOWN,LEFT},{LEFT,UP}},
    {{LEFT,UP,RIGHT},{UP,RIGHT,DOWN},{RIGHT,DOWN,LEFT},{DOWN,LEFT,UP}},
    {{LEFT,UP,RIGHT,DOWN}},
};

void add_visited(int dir, int num, int x, int y){
    vector<int> v= state[num][dir];
    visited[x][y]++;
    for(auto p: v){
        int nx=x, ny=y;
        while(1){
            nx+=dx[p]; 
            ny+=dy[p];
            if(nx<0 || nx>=n || ny<0 || ny>=m)
                break;
            if(arr[nx][ny]==6)
                break;
            visited[nx][ny]++;
        }
    }
}

void erase_visited(int dir, int num, int x, int y){
    vector<int> v= state[num][dir];
    visited[x][y]--;
    for(auto p: v){
        int nx=x, ny=y;
        while(1){
            nx+=dx[p]; 
            ny+=dy[p];
            if(nx<0 || nx>=n || ny<0 || ny>=m)
                break;
            if(arr[nx][ny]==6)
                break;
            visited[nx][ny]--;
        }
    }
}

void find_min(){
    int cnt=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(visited[i][j]==0)
                cnt++;
    
    if(cnt<mini)
        mini=cnt;
}

void backtracking(int cnt){
    if(cnt==cctv.size()){
        find_min();
        return;
    }
    int x=cctv[cnt].first, y=cctv[cnt].second;
    int cur_num=arr[x][y];
    for(int j=0;j<state[cur_num].size();j++){
        add_visited(j, cur_num, x, y);
        backtracking(cnt+1);
        erase_visited(j, cur_num, x, y);
    }
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            int input;
            cin>>input;
        
            if(input>0 && input<6){
                cctv.push_back({i,j});
            }
            if(input==6)
                visited[i][j]=-1;
            arr[i][j]=input;
        }
        backtracking(0);
        cout<<mini;
}
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

//1 이상은 뱀, 0은 아무것도 없음, -1은 사과
int main(){
    int n, k, l;
    cin>>n>>k;
    vector<vector<int>> arr;
    queue<pair<int,char>> direction;
    arr.assign(n, vector<int>(n,0));
    arr[0][0]=1;

    for(int i=0;i<k;i++){
        int x, y;
        cin>>x>>y;
        arr[x-1][y-1]=-1;
    }
    cin>>l;

    for(int i=0;i<l;i++){
        int sec;
        char dir;
        cin>>sec>>dir;
        direction.push({sec, dir});
    }

    int tic=0, dir = RIGHT;
    pair<int, int> tail={0,0}, head={0,0};
    pair<int, char> next_dir=direction.front();
    direction.pop();
    while(1){
        //방향 전환
        if(next_dir.first==tic){
            if(next_dir.second=='L'){
                if(dir==UP)
                    dir=LEFT;
                else
                    dir--;
            }
            else{
                if(dir==LEFT)
                    dir=UP;
                else
                    dir++;
            }
            if(!direction.empty()){
                next_dir=direction.front();
                direction.pop();
            }
        }
        tic++;
        int nx=head.first+dx[dir], ny=head.second+dy[dir];
        //벽
        if(nx<0 || nx>=n || ny<0 || ny>=n)
            break;
        //뱀 몸통
        else if(arr[nx][ny]>0)
            break;
        //사과
        else if(arr[nx][ny]==-1){
            arr[nx][ny]=arr[head.first][head.second]+1;
            head.first=nx;
            head.second=ny;
        }
        //빈 공간
        else{
            arr[nx][ny]=arr[head.first][head.second]+1;
            head.first=nx;
            head.second=ny;
            for(int i=0;i<4;i++){
                int t_nx=tail.first+dx[i], t_ny=tail.second+dy[i];
                if(t_nx<0 || t_nx>=n || t_ny<0 || t_ny>=n)
                    continue;
                if(arr[tail.first][tail.second]+1==arr[t_nx][t_ny]){
                    arr[tail.first][tail.second]=0;
                    tail.first=t_nx;
                    tail.second=t_ny;
                    break;
                }
            }
        }
    }
    cout<<tic;
}
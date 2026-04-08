#include <iostream>
using namespace std;

int n,m,x,y,k;
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int dice[4][3]={0,};
int arr[20][20];
pair<int,int> bottom={3,1}, top={1,1};

void move(int dir){
    int nx=x+dx[dir], ny=y+dy[dir];

    if(nx<0 || nx>=n || ny<0 || ny>=m)
        return;
    
    if(dir==0){
        swap(dice[1][2],dice[1][1]);
        swap(dice[1][1],dice[1][0]);
        swap(dice[1][0],dice[3][1]);
    }
    else if(dir==1){
        swap(dice[1][1],dice[1][0]);
        swap(dice[1][2],dice[1][1]);
        swap(dice[1][2],dice[3][1]);
    }
    else if(dir==2){
        swap(dice[0][1],dice[1][1]);
        swap(dice[1][1],dice[2][1]);
        swap(dice[2][1],dice[3][1]);
    }
    else{
        swap(dice[2][1],dice[3][1]);
        swap(dice[1][1],dice[2][1]);
        swap(dice[0][1],dice[1][1]);
    }
    x=nx, y=ny;

    if(arr[x][y]==0)
        arr[x][y]=dice[bottom.first][bottom.second];
    else{
        dice[bottom.first][bottom.second]=arr[x][y];
        arr[x][y]=0;
    }

    cout<<dice[top.first][top.second]<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>x>>y>>k;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>arr[i][j];
    
    for(int i=0;i<k;i++){
        int dir;
        cin>>dir;
        move(dir-1);
    }
}
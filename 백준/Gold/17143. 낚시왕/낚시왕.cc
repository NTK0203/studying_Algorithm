#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};

struct shark{
    int s;
    int d;
    int z;
};

vector<shark> arr[101][101];
vector<shark> temp[101][101];
bool eat[101][101];
int r, c, m, hunted=0;

void hunt(int i){
    for(int j=1;j<=r;j++){
        if(!arr[j][i].empty()){ //상어 사냥
            hunted+=arr[j][i][0].z;
            arr[j][i].pop_back();
            return;
        }
    }
}

void move(){
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            temp[i][j].clear();
    memset(eat,false,sizeof(eat));
    
    //움직이기
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(!arr[i][j].empty()){
                shark cur=arr[i][j][0];

                int dir=cur.d;
                int x=i, y=j;
                int s;

                if(dir%2==0){
                    if(r!=1)
                        s=cur.s%((r-1)*2);
                }
                else{
                    if(c!=1)
                        s=cur.s%((c-1)*2);
                }
                
                for(int k=0;k<s;k++){
                    int nx=x+dx[dir], ny=y+dy[dir];
                    if(nx<1 || nx>r || ny<1 || ny>c)
                        dir=(dir+2)%4;
                    
                    x=x+dx[dir], y=y+dy[dir];
                }
                cur.d=dir;
                if(!temp[x][y].empty() && !eat[x][y])
                    eat[x][y]=true;
                temp[x][y].push_back(cur);
            }
        }
    }
    //약육강식
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(eat[i][j]){
                shark biggist=temp[i][j][0];
                for(auto p:temp[i][j]){
                    if(biggist.z<p.z){
                        biggist=p;
                    }
                }
                temp[i][j].clear();
                temp[i][j].push_back(biggist);
            }
        }
    }
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            swap(arr[i][j],temp[i][j]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>r>>c>>m;
    for(int i=0;i<m;i++){
        shark tmp;
        int a, b, c, d, e;
        cin>>a>>b>>c>>d>>e;
        switch(d){
            case 1:
                d=0;
                break;
            case 2:
                d=2;
                break;
            case 3:
                d=3;
                break;
            case 4:
                d=1;
                break;
        }
        tmp={c,d,e};
        arr[a][b].push_back(tmp);
    }
    for(int i=1;i<=c;i++){
        hunt(i);
        move();
    }
    cout<<hunted;
}
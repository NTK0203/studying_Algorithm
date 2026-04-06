#include <iostream>
#include <vector>
using namespace std;

int r, c, t;
int arr[50][50];
vector<pair<int,int>> air;
int dx[2][4]={{-1,0,1,0},{1,0,-1,0}}; // positive:upside air, negative:downside air
int dy[4]={0,1,0,-1};

void difuse(){
    int temp[50][50]={0,};
    for(auto p:air)
        temp[p.first][p.second]=-1;
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(arr[i][j]>0){
                int cnt=0, value=arr[i][j]/5;
                for(int k=0;k<4;k++){
                    int nx=i+dx[0][k], ny=j+dy[k];

                    if(nx<0 || ny<0 || nx>=r || ny>=c)
                        continue;
                    if(arr[nx][ny]!=-1){
                        cnt++;
                        temp[nx][ny]+=value;
                    }
                }
                temp[i][j] += arr[i][j] - value*cnt;
            }
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            arr[i][j]=temp[i][j];
        }
    }
}

void cleanAir(){
    for(int i=0;i<2;i++){
        int dir=0;
        int x=air[i].first+dx[i][dir], y=air[i].second+dy[dir];
        int nx_max, nx_min;
        if(i==0)
            nx_max=air[i].first, nx_min=0;
        else
            nx_max=r-1, nx_min=air[i].first;
        if(x<0 || x>=r){
            dir++;
            x=air[i].first+dx[i][dir], y=air[i].second+dy[dir];
        }
        int nx=x+dx[i][dir], ny=y+dy[dir];
        while(1){
            if(nx<nx_min || nx>nx_max || ny<0 || ny>=c){
                dir++;

                if(dir==4)
                    break;

                nx=x+dx[i][dir], ny=y+dy[dir];
            }

            if(arr[nx][ny]==-1){
                arr[x][y]=0;
                break;
            }

            arr[x][y]=arr[nx][ny];
            x=nx, y=ny;
            nx=x+dx[i][dir], ny=y+dy[dir];
        }
    }
}

int main(){
    cin>>r>>c>>t;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            int a;
            cin>>a;
            arr[i][j]=a;

            if(a==-1)
                air.push_back({i,j}); 
        }
    }
    for(int i=0;i<t;i++){
        difuse();
        cleanAir();
    }
    int cnt=0;
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            if(arr[i][j]!=-1)
                cnt+=arr[i][j];
    cout<<cnt;
}
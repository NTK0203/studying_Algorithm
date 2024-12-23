#include <iostream>
#include <vector>
using namespace std;

int arr[9][9];
bool r[9][10],c[9][10],s[9][10];

void Tracking(int count){
    int x=count/9, y=count%9;
    if(count==81){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++)
                cout<<arr[i][j];
            cout<<"\n";
        }
        exit(0);
    }
    if(arr[x][y]==0){
        for(int i=1;i<=9;i++){
            if(!r[x][i]&&!c[y][i]&&!s[x/3*3+y/3][i]){
                r[x][i]=true;
                c[y][i]=true;
                s[x/3*3+y/3][i]=true;
                arr[x][y]=i;
                Tracking(count+1);
                r[x][i]=false;
                c[y][i]=false;
                s[x/3*3+y/3][i]=false;
                arr[x][y]=0;
            }
        }
    }
    else
        Tracking(count+1);
}

int main(){
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++){
            scanf("%1d",&arr[i][j]);
            if(arr[i][j]!=0){
                r[i][arr[i][j]]=true;
                c[j][arr[i][j]]=true;
                s[i/3*3+j/3][arr[i][j]]=true;
            }
        }
    Tracking(0);
}
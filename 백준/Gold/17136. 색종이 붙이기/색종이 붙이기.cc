#include <iostream>
using namespace std;

bool arr[10][10];
int paper[6]={0,};
int req_cnt=0, minimum=26;

void update(int x, int y, int num, bool make_zero){
    int filling;
    if(make_zero){
        paper[num]++;
        filling=0;
    }
    else{
        paper[num]--;
        filling=1;
    }

    if(num==1)
        arr[x][y]=filling;
    else
        for(int i=x;i<x+num;i++)
            for(int j=y;j<y+num;j++)
                arr[i][j]=filling;
}

bool check(int x, int y, int num){
    if(num==1){
        if(arr[x][y] && paper[num]<5)
            return true;
    }
    else if(paper[num]<5 && ((x+num-1)<10) && ((y+num-1)<10)){
        for(int i=x;i<x+num;i++)
            for(int j=y;j<y+num;j++)
                if(!arr[i][j])
                    return false;
        return true; 
    }
    return false;
}

int count_paper(){
    int cnt_paper=0;
    for(int i=1;i<6;i++)
        cnt_paper+=paper[i];
    return cnt_paper;
}

void backtracking(int x, int y, int cnt){
    if(req_cnt==cnt){
        int cnt_paper=count_paper();
        if(cnt_paper<minimum)
            minimum=cnt_paper;
        return;
    }
    for(int i=x;i<10;i++){
        if(i==x+1)
            y=0;
        for(int j=y;j<10;j++){
            if(arr[i][j]){
                for(int k=5;k>0;k--){
                    if(check(i,j,k)){
                        update(i,j,k,true);
                        backtracking(i,j,cnt+k*k);
                        update(i,j,k,false);
                    }
                }
                return;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++){
            int n;
            cin>>n;
            if(n==1){
                arr[i][j]=true;
                req_cnt++;
            }
            else
                arr[i][j]=false;
        }
    
    backtracking(0,0,0);
    if(minimum==26)
        cout<<-1;
    else
        cout<<minimum;
}
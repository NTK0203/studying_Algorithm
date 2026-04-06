#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int cnt;
char arr[100][100];
bool visited[100][100], mykey[26];
queue<pair<int,int>> waitkey[26];
queue<pair<int,int>> q;

void check_condition(int x, int y){
    if(arr[x][y]=='*')
        return;
    else if(arr[x][y]>='A' && arr[x][y]<='Z'){
        if(!mykey[arr[x][y]-'A']){
            waitkey[arr[x][y]-'A'].push({x,y});
            visited[x][y]=true;
            return;
        }
    }
    else if(arr[x][y]=='$'){
        arr[x][y]='.';
        cnt++;
    }
    else if(arr[x][y]>='a' && arr[x][y]<='z'){
        mykey[arr[x][y]-'a']=true;
        while(!waitkey[arr[x][y]-'a'].empty()){
            pair<int,int> p = waitkey[arr[x][y]-'a'].front();
                q.push(p);
                waitkey[arr[x][y]-'a'].pop();
        }
    }
    visited[x][y]=true;
    q.push({x,y});
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        fill(mykey,mykey+26,false);
        memset(visited,false,sizeof(visited));
        
        for(int j=0;j<26;j++)
            waitkey[j]=queue<pair<int,int>>();
    
        string s;
        int h,w;
        cnt=0;
        cin>>h>>w;

        for(int j=0;j<h;j++){
            cin>>s;
            for(int k=0;k<w;k++)
                arr[j][k]=s[k];
        }

        cin>>s;
        if(s!="0")
            for(int j=0;j<s.size();j++)
                mykey[s[j]-'a']=true;

        for(int j=0;j<h;j++)
            for(int k=0;k<w;k++)
                if(j==0 || j==h-1 || k==0 || k==w-1)
                    check_condition(j,k);

        while(!q.empty()){
            int x=q.front().first, y=q.front().second;
            q.pop();
            for(int j=0;j<4;j++){
                int nx=x+dx[j], ny=y+dy[j];
                if(nx<0 || nx>=h || ny<0 || ny>=w)
                    continue;
                if(!visited[nx][ny])
                    check_condition(nx,ny);
            }
        }
        cout<<cnt<<"\n";
    }
}
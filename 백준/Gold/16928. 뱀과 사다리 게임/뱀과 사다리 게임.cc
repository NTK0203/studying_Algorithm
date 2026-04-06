#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n,m,count=0;
    queue<pair<int, int>> q;
    bool visited[101]={false,}, is_ended=false;
    int updown[101]={0,};
    cin>>n>>m;
    for(int i=0;i<n+m;i++){
        int a, b;
        cin>>a>>b;
        updown[a]=b;
    }
    q.push({1,0});
    visited[1]=true;
    while(!q.empty()&&!is_ended){
        int cur=q.front().first, c_count=q.front().second+1;
        q.pop();
        for(int i=1;i<=6;i++){
            int next=cur+i;
            if(!visited[next]){
                visited[next]=true;
                if(updown[next]!=0){
                    next=updown[next];
                    visited[next]=true;
                }
                if(next==100){
                    count=c_count;
                    is_ended=true;
                    break;
                }
                q.push({next,c_count});
            }
        }
    }
    cout<<count;
}
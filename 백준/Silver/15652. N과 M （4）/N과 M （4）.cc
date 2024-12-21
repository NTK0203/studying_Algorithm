#include <iostream>
#include <algorithm>

using namespace std;
int n,m;
int arr[9]={0,};
bool visited[9]={0,};
vector<int> set;
void dfs(int, int);

int main(){
    cin>>n>>m;
    dfs(1,0);
}

void dfs(int num, int cur){
    if(cur==m){
        for(int i=0;i<m;i++)
            cout<<arr[i]<<" ";
        cout<<"\n";
        cur=0;
        return;
    }
    for(int i=num;i<=n;i++){
            arr[cur]=i;
            dfs(i, cur+1);
        }
}
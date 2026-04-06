#include <iostream>
#include <vector>
using namespace std;

vector<int> list[100001];
int value[100001]={0,};

int makeTree(int cur, int parent){
    value[cur]=1;
    for(auto childNode : list[cur]){
        if(childNode != parent){
            value[cur]+=makeTree(childNode, cur);
        }
    }
    return value[cur];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,r,q;
    cin>>n>>r>>q;
    for(int i=1;i<n;i++){
        int u, v;
        cin>>u>>v;
        list[u].push_back(v);
        list[v].push_back(u);
    }
    makeTree(r,-1);

    for(int i=q;i>0;i--){
        cin>>q;
        cout<<value[q]<<"\n";
    }
}
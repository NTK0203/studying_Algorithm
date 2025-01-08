#include <iostream>
#include <vector>
using namespace std;

int n,m;
bool check=true;
vector<int> parent;

int find(int a){
    if(parent[a]==a) return a;
    return parent[a]=find(parent[a]);
}

void merge(int a, int b){
    a=find(a);
    b=find(b);
    if(a!=b)
        parent[b]=a;
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++)
        parent.push_back(i);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        if(find(a)==find(b)){
            cout<<i+1;
            check=false;
            break;
        }
        merge(a,b);
    }
    if(check)
        cout<<0;
}
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

deque<int> q;
vector<int> v;

void popb(int idx){
    while(!q.empty()){
        int cur=q.back();
        if(v[cur]<v[idx])
            break;
        q.pop_back();
    }
    q.push_back(idx);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    v.push_back(-1);
    int n,l;
    cin>>n>>l;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        v.push_back(num);
    }
    q.push_back(1);
    cout<<v[1]<<" ";
    for(int i=2;i<=l;i++){
        popb(i);
        cout<<v[q.front()]<<" ";
    }
    for(int i=l+1;i<=n;i++){
        if(q.front()<(i-l+1))
            q.pop_front();
        popb(i);
        cout<<v[q.front()]<<" ";
    }
}
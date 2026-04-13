#include <iostream>
using namespace std;

int set[100000];

void init_set(int g){
    for(int i=1;i<=g;i++)
        set[i]=i;
}

int find_set(int g){
    if(set[g]==g)
        return g;
    return set[g]=find_set(set[g]);
}

void merge(int u, int v){
    u=find_set(u);
    v=find_set(v);
    if(u==v)
        return;
    set[v]=u;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int g, p, cnt=0;
    cin>>g>>p;

    init_set(g);
    bool is_zero=false;

    for(int i=0;i<p;i++){
        int g_i;
        cin>>g_i;

        int parent=find_set(g_i);

        if(is_zero)
            continue;

        if(parent==0){
            is_zero=true;
            continue;
        }

        merge(parent-1,parent);

        cnt++;
    }
    cout<<cnt;
}
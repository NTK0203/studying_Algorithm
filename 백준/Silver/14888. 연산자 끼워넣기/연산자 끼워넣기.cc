#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector<int> v, op;
bool visited[11];
int n, M=-1000000000, m=1000000000;

void calculate(vector<int> cur){
    int total=v[0];
    for(int i=0;i<cur.size();i++){
        int cur_operator=cur[i];
        switch (cur_operator)
        {
        case 0:
            total+=v[i+1];
            break;
        case 1:
            total-=v[i+1];
            break;
        case 2:
            total*=v[i+1];
            break;
        default:
            total/=v[i+1];
            break;
        }
    }
    M=max(M,total);
    m=min(m,total);
}

void backtracking(int count, vector<int> cur){
    if(count==n-1){
        calculate(cur);
        return;
    }
    for(int i=0;i<n-1;i++){
            if(!visited[i]){
                visited[i]=true;
                cur.push_back(op[i]);
                backtracking(count+1,cur);
                cur.pop_back();
                visited[i]=false;
            }
        }

}

int main(){
    memset(visited, false, sizeof(visited));
    cin>>n;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        v.push_back(num);
    }
    for(int i=0;i<4;i++){
        int num;
        cin>>num;
        for(int j=0;j<num;j++)
            op.push_back(i);
    }
    vector<int> cur;
    backtracking(0,cur);
    cout<<M<<"\n"<<m;
}
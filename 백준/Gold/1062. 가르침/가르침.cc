#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n, k, result=0;
vector<string> v;
bool visited[26];

bool check(string s){
    for(int i=4;i<s.size()-4;i++){
        int idx=s[i]-'a';
        if(!visited[idx])
            return false;
    }
    return true;
}

void backtracking(int cnt, int idx){
    if(cnt==k){
        int num=0;
        for(int i=0;i<v.size();i++)
            if(check(v[i]))
                num++;
        
        if(result<num)
            result=num;

        return;
    }
    for(int i=idx;i<26;i++){
        if(!visited[i]){
            visited[i]=true;
            backtracking(cnt+1, i+1);
            visited[i]=false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(visited,false,sizeof(visited));
    visited[0]=true;
    visited['n'-'a']=true;
    visited['t'-'a']=true;
    visited['i'-'a']=true;
    visited['c'-'a']=true;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        v.push_back(s);
    }
    if(k>=5)
        backtracking(5, 0);
    cout<<result;
}
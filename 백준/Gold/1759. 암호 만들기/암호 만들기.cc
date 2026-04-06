#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<char> arr;
char mother[5]={'a','e','i','o','u'};
int l, c;

bool check(string s){
    int mom_cnt=0;
    bool has_mom=false;
    for(int i=0;i<s.size();i++){
        for(int j=0;j<5;j++)
            if(s[i]==mother[j]){
                mom_cnt++;
                has_mom=true;
                break;
            }
    }
    if(has_mom && ((l-mom_cnt)>=2))
        return true;
    return false;
}

void backtracking(int count, int pre_idx, string s){
    if(count==l){
        if(check(s))
            cout<<s<<"\n";
        return;
    }

    for(int i=pre_idx;i<c;i++)
            backtracking(count+1,i+1,s+arr[i]);
}

int main(){
    cin>>l>>c;
    for(int i=0;i<c;i++){
        char c;
        cin>>c;
        arr.push_back(c);
    }
    sort(arr.begin(), arr.end());
    
    string s="";

    backtracking(0,0,s);
}
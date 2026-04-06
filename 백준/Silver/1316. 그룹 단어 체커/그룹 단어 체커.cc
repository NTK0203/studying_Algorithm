#include <iostream>
#include <string>
using namespace std;

int main(){
    int n, count=0;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        char pre_c;
        bool is_group[26]={false,}, not_group=false;
        cin>>s;
        for(int j=0;j<s.size();j++){
            int cur_index=s[j]-'a';
            if(!is_group[cur_index]){
                is_group[cur_index]=true;
                pre_c=s[j];
            }
            else{
                if(pre_c!=s[j]){
                    not_group=true;
                    break;
                }
            }
        }
        if(!not_group){
            count++;
        }
    }
    cout<<count;
}
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    bool skip_list[26];
    fill(skip_list,skip_list+26,false);
    for(int i=0;i<skip.size();i++)
        skip_list[skip[i]-'a']=true;
    for(auto p:s){
        for(int i=0;i<index;i++){
            p++;
            if((p-'a')>=26)
                p='a';
            if(skip_list[p-'a'])
                i--;
        }
        answer.push_back(p);
    }
    return answer;
}
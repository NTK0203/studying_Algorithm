#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int idx[26];
    for(int i=0;i<26;i++)
        idx[i]=-1;
    for(int i=0;i<s.size();i++){
        int cur=s[i]-'a';
        if(idx[cur]==-1)
            answer.push_back(-1);
        else
            answer.push_back(i-idx[cur]);
        idx[cur]=i;
    }
    return answer;
}
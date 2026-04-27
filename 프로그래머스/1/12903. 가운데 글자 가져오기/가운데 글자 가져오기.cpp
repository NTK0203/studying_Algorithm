#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int size=s.size();
    if(size%2==0){
        int idx=size/2-1;
        answer.push_back(s[idx]);
        answer.push_back(s[idx+1]);
    }
    else{
        int idx=size/2;
        answer.push_back(s[idx]);
    }
    return answer;
}
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    int x[10]={0,}, y[10]={0,};
    for(int i=0;i<X.size();i++)
        x[(X[i]-'0')]++;
    for(int i=0;i<Y.size();i++)
        y[(Y[i]-'0')]++;
    for(int i=9;i>=0;i--){
        int num=min(x[i],y[i]);
        for(int j=0;j<num;j++)
            answer.push_back(i+'0');
    }
    if(answer=="")
        return "-1";
    if(answer[0]=='0')
        return "0";
    return answer;
}
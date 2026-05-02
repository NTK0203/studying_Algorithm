#include <string>
#include <vector>
#include <stack>
using namespace std;

string solution(vector<int> food) {
    string answer = "";
    stack<int> s;
    for(int i=1;i<food.size();i++){
        for(int j=0;j<(food[i]/2);j++){
            answer.push_back(i+'0');
            s.push(i);
        }
    }
    answer.push_back('0');
    while(!s.empty()){
        answer.push_back(s.top()+'0');
        s.pop();
    }
    return answer;
}
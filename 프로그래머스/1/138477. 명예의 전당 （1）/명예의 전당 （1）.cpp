#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    priority_queue<int, vector<int>, greater<int>> q;
    
    for(auto p:score){
        if(q.size()<k)
            q.push(p);
        else
            if(q.top()<p){
                q.pop();
                q.push(p);
            }
        answer.push_back(q.top());
    }
    return answer;
}
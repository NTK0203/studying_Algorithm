#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    answer.push_back(arr[0]);
    for(auto p:arr){
        if(answer.back()==p)
            continue;
        answer.push_back(p);      
    }
    return answer;
}
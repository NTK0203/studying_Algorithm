#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    for(int i=0;i<section.size();i++){
        if(section[i]==0)
            continue;
        answer++;
        int paint = section[i]+m-1;
        for(int j=i;j<section.size();j++){
            if(section[j]<=paint){
                section[j]=0;
            }
        }
    }
    return answer;
}
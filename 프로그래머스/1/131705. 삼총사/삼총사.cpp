#include <string>
#include <vector>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    for(int i=0;i<number.size();i++){
        for(int j=i+1;j<number.size();j++){
            int twin=number[i]+number[j];
            for(int k=j+1;k<number.size();k++){
                if(twin+number[k]==0)
                    answer++;
            }
        }
    }
    return answer;
}
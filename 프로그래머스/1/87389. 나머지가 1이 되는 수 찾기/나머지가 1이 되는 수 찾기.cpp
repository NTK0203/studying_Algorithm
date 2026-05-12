#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = n-1;
    for(int i=answer-1;i>1;i--)
        if(n%i==1)
            answer=i;
    return answer;
}
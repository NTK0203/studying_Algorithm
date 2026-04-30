#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    long long num_p=stoll(p);

    for(int i=0;i<t.size()-p.size()+1;i++){
        long long num_t=stoll(t.substr(i,p.size()));
        
        if(num_t<=num_p)
            answer++;
    }
    return answer;
}
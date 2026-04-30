#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    for(int i=0;i<t.size()-p.size()+1;i++){
        bool check=true;
        for(int j=i;j<i+p.size();j++){
            if(t[j]>p[j-i]){
                check=false;
                break;
            }
            else if(t[j]<p[j-i])
                break;
        }
        if(check)
            answer++;
    }
    return answer;
}
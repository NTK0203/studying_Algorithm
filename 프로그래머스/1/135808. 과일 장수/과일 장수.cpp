#include <string>
#include <vector>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    vector<int> v(k+1);
    fill(v.begin(), v.end(), 0);
    for(auto p:score)
        v[p]++;
    int rest=0;
    for(int i=k;i>0;i--){
        answer+=((rest+v[i])/m)*i*m;
        rest=(v[i]+rest)%m;
    }
    return answer;
}
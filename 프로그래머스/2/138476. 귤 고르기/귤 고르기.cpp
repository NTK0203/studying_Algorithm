#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int, greater<int>> m;
    sort(tangerine.begin(), tangerine.end());
    int prev=tangerine[0], count=0;
    for(auto p:tangerine){
        if(p!=prev){
            if(m.find(count)==m.end())
                m.insert({count,1});
            else
                m[count]++;
            count=0;
            prev=p;
        }
        count++;
    }
    
    if(m.find(count)==m.end())
        m.insert({count,1});
    else
        m[count]++;
    
    for(pair<int,int> p:m){
        for(int i=0;i<p.second;i++){
            k-=p.first;
            answer++;
            if(k<=0)
                return answer;
        }
    }
}
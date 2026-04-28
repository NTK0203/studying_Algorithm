#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    return a.second<b.second;
}

int solution(vector<vector<int>> targets) {
    int answer = 1;
    vector<pair<int,int>> v;
    
    for(auto p:targets)
        v.push_back({p[0],p[1]});
    
    sort(v.begin(),v.end(),cmp);
    
    int pre_tail=v[0].second;
    
    for(int i=1;i<v.size();i++){
        int cur_head=v[i].first;
        int cur_tail=v[i].second;
        if(cur_head<pre_tail && pre_tail<=cur_tail)
            continue;
        pre_tail=cur_tail;
        answer++;
    }
    
    return answer;
}
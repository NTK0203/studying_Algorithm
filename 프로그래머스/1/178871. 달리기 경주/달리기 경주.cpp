#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string, int> m;
    
    for(int i=0;i<players.size();i++)
        m.insert({players[i],i});
    
    for(auto p:callings){
        int cur_rank=m[p];
        m[p]=cur_rank-1;
        m[players[cur_rank-1]]=cur_rank;
        swap(players[cur_rank],players[cur_rank-1]);
    }
    
    return players;
}
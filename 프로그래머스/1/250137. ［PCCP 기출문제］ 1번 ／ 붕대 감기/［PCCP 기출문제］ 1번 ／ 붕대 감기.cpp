#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int prev_t = 0;
    int cur_health = health;
    for(int i=0;i<attacks.size();i++){
        int cur_t = attacks[i][0];
        cur_health += bandage[1]*(cur_t-prev_t-1) + (cur_t-prev_t-1)/bandage[0]*bandage[2];
        
        if(cur_health>health)
            cur_health=health;
        
        cur_health -= attacks[i][1];
        
        if(cur_health<=0){
            cur_health=-1;
            break;
        }
        prev_t = cur_t;
    }
    return cur_health;
}
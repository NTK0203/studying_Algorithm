#include <string>
#include <vector>
using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    int idx1=0, idx2=0;
    for(auto p:goal){
        bool pass=false;
        if(idx1<cards1.size())
            if(cards1[idx1].compare(p)==0){
                idx1++;
                pass=true;
            }
    
        if(!pass && idx2<cards2.size())
            if(cards2[idx2].compare(p)==0){
                idx2++;
                pass=true;
            }
        
        if(!pass){
            answer="No";
            break;
        }
    }
    return answer;
}
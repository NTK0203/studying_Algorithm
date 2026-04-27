#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

vector<string> split(string s, char p){
    istringstream buf(s);
    vector<string> v;
    string temp;
    while(getline(buf,temp,p)){
        v.push_back(temp);
    }
    return v;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> result;
    vector<string> v_today=split(today,'.');
    int today_date=stoi(v_today[0])*12*28+(stoi(v_today[1])-1)*28+stoi(v_today[2]);
    unordered_map<string, int> uomap;
    
    for(auto p:terms){
        vector<string> v=split(p,' ');
        uomap.insert({v[0],stoi(v[1])});
    }
    
    for(int i=0;i<privacies.size();i++){
        vector<string> v=split(privacies[i],'.');
        vector<string> temp=split(v[2],' ');
        v[2]=temp[0];
        int cur_date=stoi(v[0])*12*28+(stoi(v[1])-1)*28+stoi(v[2]);
        int exp=uomap[temp[1]];
        cur_date+=exp*28;
        if(cur_date<=today_date)
            result.push_back(i+1);
    }
    return result;
}
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> v;
    for(auto p:arr){
        if(p%divisor==0)
            v.push_back(p);
    }
    if(v.empty())
        v.push_back(-1);
    else
        sort(v.begin(),v.end());
    return v;
}
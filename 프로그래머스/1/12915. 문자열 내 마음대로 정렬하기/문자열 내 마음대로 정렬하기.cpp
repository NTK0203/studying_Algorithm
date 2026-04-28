#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int idx;

bool cmp(string a, string b){
    if(a[idx]<b[idx]) 
        return true;
    else if(a[idx]==b[idx])
        return b.compare(a)>0?true:false;
    else
        return false;
}

vector<string> solution(vector<string> strings, int n) {
    idx=n;
    sort(strings.begin(),strings.end(),cmp);
    return strings;
}
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int arr[200001]={0,};
    int cnt=0;
    for(auto p:nums)
        if(arr[p]++==0)
            cnt++;
    if(cnt>(nums.size()/2))
        cnt=nums.size()/2;
    
    int answer = cnt;
    return answer;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int num;
    vector<int> arr;
    cin>>num;
    while(num!=0){
        arr.push_back(num%10);
        num/=10;
    }
    sort(arr.rbegin(), arr.rend());
    for(int i=0;i<arr.size();i++)
        cout<<arr[i];
}
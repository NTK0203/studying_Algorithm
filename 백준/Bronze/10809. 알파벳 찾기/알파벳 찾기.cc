#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string s;
    int arr[26];
    fill(arr, arr+26,-1);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(arr[s[i]-'a']==-1)
            arr[s[i]-'a']=i;
    }
    
    for(int i=0;i<26;i++)
        cout<<arr[i]<<" ";
}
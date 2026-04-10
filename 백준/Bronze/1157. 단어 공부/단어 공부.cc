#include <iostream>
using namespace std;

int main(){
    int arr[26]={0,}, M=0,max_idx=-1;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        char c=s[i], idx=c-'A';
        if(idx>=26)
            idx=c-'a';
        arr[idx]++;
    }
    for(int i=0;i<26;i++){
        if(M<=arr[i]){
            M=arr[i];
            max_idx=i;
        }
    }
    int same=0;
    for(int i=0;i<26;i++){
        if(arr[i]==M)
            same++;
    }
    if(same>1)
        cout<<"?";
    else
        cout<<char(max_idx+'A');
}
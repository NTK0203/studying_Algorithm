#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s, boom;
    vector<char> arr;
    cin>>s>>boom;
    
    for(int i=0;i<s.size();i++){
        arr.push_back(s[i]);
        if(arr.size()>=boom.size()){
            bool is_same=true;
            for(int j=0;j<boom.size();j++){
                int idx=arr.size()-boom.size()+j;
                if(arr[idx]!=boom[j]){
                    is_same=false;
                    break;
                }
            }
            if(is_same){
                for(int j=0;j<boom.size();j++)
                    arr.pop_back();
            }
        }
    }
    if(arr.empty())
        cout<<"FRULA";
    else
        for(int i=0;i<arr.size();i++)
            cout<<arr[i];
}
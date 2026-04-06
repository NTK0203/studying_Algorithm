#include <iostream>
#include <string>
using namespace std;

int main(){
    int t;
    cin>>t;
    cin.ignore();
    for(int i=0;i<t;i++){
        string s, tmp="";
        getline(cin, s);
        for(int j=0;j<s.size();j++){
            if(s[j]!=' '){
                tmp.push_back(s[j]);
            }
            else{
                for(int k=tmp.size()-1;k>=0;k--)
                    cout<<tmp[k];
                cout<<" ";
                tmp="";
            }
        }
        for(int k=tmp.size()-1;k>=0;k--)
                    cout<<tmp[k];
                cout<<"\n";
                tmp="";
    }
}
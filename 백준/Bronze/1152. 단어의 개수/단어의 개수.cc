#include <iostream>
using namespace std;

int main(){
    int cnt=0;
    string s;
    getline(cin, s);
    for(int i=0;i<s.size();i++){
        if(s[i]!=' ')
            if(s[i-1]==' ' || i==0)
                cnt++;
    }
    cout<<cnt;
}
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    map<string, string> mm;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string site, pw;
        cin>>site>>pw;
        mm.insert({site, pw});
    }
    for(int j=0;j<m;j++){
        string s;
        cin>>s;
        cout<<mm[s]<<"\n";
    }
}
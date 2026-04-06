#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n, result = 1;
        map<string, int> m;
        cin>>n;
        for(int j=0;j<n;j++){
            string name, category;
            cin>>name>>category;
            if(m.find(category) != m.end()){
                m[category]++;
            }
            else{
                m.insert({category,1});
            }
        }
        for(auto itr = m.begin();itr != m.end();itr++){
            result*=itr->second+1;
        }
        result-=1;
        if(n==0)
            result=0;
        cout<<result<<"\n";
    }
}
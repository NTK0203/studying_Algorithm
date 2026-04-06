#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        multiset<int> q;
        int k;
        cin>>k;
        for(int j=0;j<k;j++){
            char c;
            int n;
            cin>>c>>n;
            if(c=='I'){
                q.insert(n);
            }
            else{
                if(q.empty())
                    continue;

                if(n==-1)
                    q.erase(q.begin());
                else{
                    auto p = q.end();
                    p--;
                    q.erase(p);
                }
            }
        }
        if(q.empty())
            cout<<"EMPTY\n";
        
        else{
            cout<<*q.rbegin()<<" "<<*q.begin()<<"\n";
        }
    }
}
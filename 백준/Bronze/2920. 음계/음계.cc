#include <iostream>
using namespace std;

int main(){
    int first, itr=-1;
    cin>>first;
    if(first==1){
        itr=0;
        for(int i=first+1;i<9;i++){
            int n;
            cin>>n;
            if(n!=i){
                itr=-1;
                break;
            }
        }
    }
    else if(first==8){
        itr=1;
        for(int i=first-1;i>0;i--){
            int n;
            cin>>n;
            if(n!=i){
                itr=-1;
                break;
            }
        }
    }
    if(itr==-1)
        cout<<"mixed";
    else if(itr==0)
        cout<<"ascending";
    else
        cout<<"descending";
    
}
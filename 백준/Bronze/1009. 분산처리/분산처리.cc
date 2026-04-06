#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int a, b, mul;
        cin>>a>>b;
        mul=a;
        mul%=10;
        for(int j=1;j<b;j++){
            mul*=a;
            mul%=10;
        }
        if(mul==0)
            cout<<10<<"\n";
        else
            cout<<mul<<"\n";
    }
}
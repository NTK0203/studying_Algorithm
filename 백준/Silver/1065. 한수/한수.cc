#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    if(n<100)
        cout<<n;
    else{
        int count=0;
        for(int i=100;i<=n;i++){
            int hund=i/100, ten=i%100/10, one=i%10;
            if(hund+one==2*ten)
                count++;
        }
        cout<<count+99;
    }
}
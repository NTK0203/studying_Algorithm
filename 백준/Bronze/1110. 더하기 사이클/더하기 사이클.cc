#include <iostream>
using namespace std;

int main(){
    int n, cnt=1;
    cin>>n;
    int num=n;
    num=(num/10+num%10)%10+(num%10)*10;
    while(1){
        if(num==n)
            break;
        num=(num/10+num%10)%10+(num%10)*10;
        cnt++;
    }
    cout<<cnt;
}
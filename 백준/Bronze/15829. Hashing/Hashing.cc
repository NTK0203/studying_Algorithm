#include <iostream>
#include <string>
using namespace std;

int main(){
    long long n, mul=1, result=0;
    string s;
    cin>>n>>s;
    for(int i=0;i<n;i++){
        long long cur=s[i]-'a'+1;
        cur*=mul%1234567891;
        result+=cur;
        result%=1234567891;
        mul=mul*31%1234567891;
    }
    cout<<result;
}
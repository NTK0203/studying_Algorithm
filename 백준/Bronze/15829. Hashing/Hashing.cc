#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int n, result=0;
    string s;
    cin>>n>>s;
    for(int i=0;i<n;i++){
        int cur=s[i]-'a'+1;
        int mul=1;
        for(int j=0;j<i;j++)
            mul*=31;
        cur*=mul;
        result+=cur;
    }
    cout<<result;
}
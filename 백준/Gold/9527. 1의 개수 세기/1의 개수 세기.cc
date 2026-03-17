#include <iostream>
#include <cmath>
using namespace std;

int getexp(long long num){
    int count=-1;
    while(num>0){
        num/=2;
        count++;
    }
    return count;
}

long long func(long long num){
    if(num<1)
        return num;
    int exp=getexp(num);
    return exp*(1LL<<(exp-1)) + num-(1LL<<exp)+1 + func(num-(1LL<<exp));
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long a, b;
    cin>>a>>b;
    cout<<func(b)-func(a-1);
}
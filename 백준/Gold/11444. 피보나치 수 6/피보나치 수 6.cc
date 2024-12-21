#include <iostream>
#include <map>
using namespace std;

long long m[2][2]={{0,1},{1,1}};
map<long long, long long> f;

long long fibo(long long n){
    if(f[n])
        return f[n];
    if(n%2==0)
        f[n]=(fibo(n/2)*(fibo(n/2+1)+fibo(n/2-1)))%1000000007;
    else
        f[n]=(fibo((n+1)/2)*fibo((n+1)/2)+fibo((n-1)/2)*fibo((n-1)/2))%1000000007;
    return f[n];
}

int main(){
    long long n;
    cin>>n;
    f[0]=0;
    f[1]=1;
    f[2]=1;
    cout<<fibo(n);
}
#include <iostream>
using namespace std;
int main(){
    int N,count=0;
    int *A;
    long long K;
    cin>>N>>K;
    A=new int[N];
    for(int i=0;i<N;i++)
        cin>>A[i];
    for(int j=N-1;j>=0;j--)
    {
        while(K>=A[j])
        {
            K-=A[j];
            count++;
        }
    }
    cout<<count<<"\n";
}
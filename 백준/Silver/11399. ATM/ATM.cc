#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N,count=0;
    int *P;
    cin>>N;
    P=new int[N];
    for(int i=0;i<N;i++)
        cin>>P[i];
    sort(P,P+N);
    for(int j=0;j<N;j++)
        for(int k=0;k<=j;k++)
            count+=P[k];
    cout<<count<<"\n";
}
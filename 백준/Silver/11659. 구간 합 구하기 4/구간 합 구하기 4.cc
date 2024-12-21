#include <iostream>
using namespace std;

int* N_num=new int[100001];
int* sumarr=new int[100001];
int sum(int,int,int);

int main()
{
    int N, M, i, j;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M;
    for(int k=1;k<N+1;k++)
        cin>>N_num[k];
    for(int k=1;k<N+1;k++)
        sumarr[k]=sumarr[k-1]+N_num[k];
    for(int k=1;k<M+1;k++)
    {
        cin>>i>>j;
        cout<<sumarr[j]-sumarr[i-1]<<"\n";
    }
}
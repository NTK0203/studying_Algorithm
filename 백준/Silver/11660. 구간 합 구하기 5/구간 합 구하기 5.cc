#include <iostream>
using namespace std;

int N_num[1025][1025]={0,};
int sumarr[1025][1025]={0,};

int main()
{
    int N, M, x_1, y_1, x_2, y_2, result;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            cin>>N_num[i][j];
            
     for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            sumarr[i][j]=N_num[i][j]+(sumarr[i-1][j]+sumarr[i][j-1]-sumarr[i-1][j-1]);
            
    for(int i=1;i<=M;i++)
    {
        cin>>x_1>>y_1>>x_2>>y_2;
        result = sumarr[x_2][y_2]-(sumarr[x_1-1][y_2]+sumarr[x_2][y_1-1]-sumarr[x_1-1][y_1-1]);
        cout<<result<<"\n";
    }
}
#include <iostream>
using namespace std;
int fb[41][2]={};
void fibonacci() {
    fb[0][0]=1;
    fb[0][1]=0;
    fb[1][0]=0;
    fb[1][1]=1;
    for(int i=2;i<41;i++)
    {
        fb[i][0]=fb[i-1][0]+fb[i-2][0];
        fb[i][1]=fb[i-1][1]+fb[i-2][1];
    }
}

int main(){
    fibonacci();
    int T;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        int N=0;
        cin>>N;
        cout<<fb[N][0]<<" "<<fb[N][1]<<"\n";
    }
}
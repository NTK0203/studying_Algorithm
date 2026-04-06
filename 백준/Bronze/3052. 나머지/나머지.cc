#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int cnt=0;
    bool arr[42];
    memset(arr,false,sizeof(arr));
    for(int i=0;i<10;i++){
        int n;
        cin>>n;
        if(!arr[n%42]){
            arr[n%42]=true;
            cnt++;
        }
    }
    cout<<cnt;
}
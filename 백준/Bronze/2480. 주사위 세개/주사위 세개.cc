#include <iostream>
using namespace std;

int main(){
    int n, same=1, same_idx, max=1;
    int arr[7]={0,};
    for(int i=0;i<3;i++){
        cin>>n;
        arr[n]++;
        if(arr[n]>=2){
            same++;
            same_idx=n;
        }
        if(n>max)
            max=n;
    }
    switch(same){
        case 1:
            cout<<max*100;
            break;
        case 2:
            cout<<1000+same_idx*100;
            break;
        case 3:
            cout<<10000+same_idx*1000;
            break;
    }
}
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> arr, inc_arr;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    inc_arr.push_back(arr[0]);
    for(int i=1;i<n;i++){
        if(inc_arr[inc_arr.size()-1]<arr[i])
            inc_arr.push_back(arr[i]);
        else{
            int low=0, up=inc_arr.size(), s=0;
            while(low<up){
                s=(up+low)/2;
                if(inc_arr[s]>=arr[i]){
                    up=s;
                }
                else{
                    low=s+1;
                }
            }
            inc_arr[up]=arr[i];

        }
    }
    cout<<inc_arr.size();
}
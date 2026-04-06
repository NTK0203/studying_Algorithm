#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> arr, inc_arr;
    int index_check[1000000];
    fill(index_check, index_check+1000000, -1);
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    inc_arr.push_back(arr[0]);
    index_check[0]=0;
    for(int i=1;i<n;i++){
        if(inc_arr[inc_arr.size()-1]<arr[i]){
            inc_arr.push_back(arr[i]);
            index_check[i]=inc_arr.size()-1;
        }
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
            index_check[i]=up;
        }
    }
    int count=inc_arr.size();
    cout<<count--<<"\n";
    inc_arr.clear();
    for(int i=n-1;i>=0;i--){
        int cur_num = index_check[i];
        if(cur_num==-1)
            continue;
        if(count==cur_num){
            count--;
            inc_arr.push_back(arr[i]);
        }
    }
    for(int i=inc_arr.size()-1;i>=0;i--)
        cout<<inc_arr[i]<<" ";
}
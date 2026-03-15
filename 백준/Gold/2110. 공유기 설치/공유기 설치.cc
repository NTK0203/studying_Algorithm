#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    vector<int> loc_x;
    int n, c;
    cin>>n>>c;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        loc_x.push_back(x);
    }

    sort(loc_x.begin(), loc_x.end());

    int front=1, back=loc_x.back()-loc_x.front();
    while(front<=back){
        int c_cnt=c-1;
        int mid = (front+back)/2;
        int pre_loc=loc_x[0];
        for(int i=1;i<n && c_cnt!=0;i++){
            int cur_loc=loc_x[i];
            if(cur_loc-pre_loc>=mid){
                c_cnt--;
                pre_loc=cur_loc;
            }
        }
        if(c_cnt==0)
            front=mid+1;
        else
            back=mid-1;
    }
    cout<<back;
}
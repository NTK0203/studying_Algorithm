#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    long long count=0;
    cin>>n;
    vector<int> arr[n], ab, cd;

    for(int i=0;i<n;i++)
        for(int j=0;j<4;j++){
            int num;
            cin>>num;
            arr[i].push_back(num);
        }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            ab.push_back(arr[i][0]+arr[j][1]);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cd.push_back(arr[i][2]+arr[j][3]);
    
    sort(cd.begin(), cd.end());
    
    for(int i=0;i<ab.size();i++){
        int ab_num=-ab[i];
        auto upper=upper_bound(cd.begin(),cd.end(),ab_num);
        auto lower=lower_bound(cd.begin(),cd.end(),ab_num);
        count+=upper-lower;
    }

    cout<<count;
}
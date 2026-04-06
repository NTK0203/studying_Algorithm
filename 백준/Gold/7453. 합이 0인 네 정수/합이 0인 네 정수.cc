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
    
    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());

    int ab_ptr=0, cd_ptr=cd.size()-1;

    while(ab_ptr<ab.size() && cd_ptr>=0){
        if(ab[ab_ptr]+cd[cd_ptr]==0){
            long long ab_count=0, cd_count=0;
            int temp_ab=ab[ab_ptr];
            for(;ab_ptr<ab.size() && ab[ab_ptr]+cd[cd_ptr]==0;ab_ptr++)
                ab_count++;
                
            for(;cd_ptr<cd.size() && temp_ab+cd[cd_ptr]==0;cd_ptr--)
                cd_count++;
            count+=ab_count*cd_count;
        }
        else if((-ab[ab_ptr])>cd[cd_ptr]){
            ab_ptr++;
        }
        else
            cd_ptr--;
    }

    cout<<count;
}
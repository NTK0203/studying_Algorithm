#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n,k;
long long total=0;
vector<int> bag;
vector<pair<int,int>> arr;

int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int m,v;
        cin>>m>>v;
        arr.push_back(make_pair(m,v));
    }
    for(int i=0;i<k;i++){
        int c;
        cin>>c;
        bag.push_back(c);
    }
    sort(arr.begin(),arr.end());
    sort(bag.begin(),bag.end());
    
    priority_queue<int> q;
    int j=0;

    for(int i=0;i<k;i++){
        for(;arr.size()>j&&arr[j].first<=bag[i];j++)
            q.push(arr[j].second);
        if(!q.empty()){
            total+=q.top();
            q.pop();
        }
    }
    cout<<total;
}
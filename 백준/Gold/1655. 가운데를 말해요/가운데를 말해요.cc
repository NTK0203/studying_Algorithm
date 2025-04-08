#include <iostream>
#include <functional>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N,input,mid;
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;
    cin>>N;
    cin>>mid;
    cout<<mid<<"\n";
    for(int i=1;i<N;i++)
    {
        cin>>input;
        if(mid<input)
        {
            minheap.push(input);
            if(maxheap.size()+1<minheap.size())
            {
                maxheap.push(mid);
                mid=minheap.top();
                minheap.pop();
            }
        }
        else
        {
            maxheap.push(input);
            if(maxheap.size()>minheap.size())
            {
                minheap.push(mid);
                mid=maxheap.top();
                maxheap.pop();
            }
        }
        cout<<mid<<"\n";
    }
}
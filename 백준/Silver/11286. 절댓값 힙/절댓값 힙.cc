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
    for(int i=0;i<N;i++)
    {
        cin>>input;
        if(input==0)
        {
            if(maxheap.empty()&&minheap.empty())
                cout<<0<<"\n";
            else if(maxheap.empty())
            {
                cout<<minheap.top()<<"\n";
                minheap.pop();
            }
            else if(minheap.empty())
            {
                cout<<maxheap.top()<<"\n";
                maxheap.pop();
            }
            else if(-maxheap.top()>minheap.top())
            {
                cout<<minheap.top()<<"\n";
                minheap.pop();
            }
            else if(-maxheap.top()<=minheap.top())
            {
                cout<<maxheap.top()<<"\n";
                maxheap.pop();
            }
        }
        else if(input<0)
            maxheap.push(input);
        else
            minheap.push(input);  
    }
}
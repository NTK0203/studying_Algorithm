#include <iostream>
#include <functional>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    long long input;
    priority_queue<long long> minheap;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>input;
        if(input==0)
        {
            if(minheap.empty())
                cout<<0<<"\n";
            else
            {
                cout<<minheap.top()<<"\n";
                minheap.pop();
            }
        }
        else
            minheap.push(input);  
    }
}
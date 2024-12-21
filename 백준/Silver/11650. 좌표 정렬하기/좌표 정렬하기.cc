#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
bool compare(const pair<int, int>&, const pair<int, int>&);
int main(){
    int N;
    int first, second;
    cin>>N;
    pair<int, int> *room=new pair<int, int>[N];
    for(int i=0;i<N;i++)
    {
        cin>>first>>second;
        room[i]=make_pair(first,second);
    }
    sort(room,room+N, compare);
    for(int j=0;j<N;j++)
        cout<<room[j].first<<" "<<room[j].second<<"\n";
}
bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
    if(a.first==b.first)
        return a.second<b.second;
    else
        return a.first<b.first;
}
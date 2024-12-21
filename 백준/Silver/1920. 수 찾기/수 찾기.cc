#include <iostream>
#include <algorithm>
bool BinarySearch(int*,int,int);
using namespace std;

int main()
{
    int beforein,afterin;
    int *beforenum,*afternum;
    cin>>beforein;
    beforenum= new int[beforein];
    for(int i=0;i<beforein;i++)
        cin>>beforenum[i];
    sort(beforenum,beforenum+beforein);
    cin>>afterin;
    afternum= new int[afterin];
    for(int i=0;i<afterin;i++)
        cin>>afternum[i];
    for(int i=0;i<afterin;i++)
        if(BinarySearch(beforenum,beforein,afternum[i]))
            cout<<1<<'\n';
        else
            cout<<0<<'\n';
}
bool BinarySearch(int *array,int length,int n)
{
    int first=0;
    int last=length-1;
    while(last>=first)
    {
        int mid=(first+last)/2;
        if(array[mid]==n)
            return true;
        else if(array[mid]<n)
            first=mid+1;
        else
            last=mid-1;
    }
    return false;
}
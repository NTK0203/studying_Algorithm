#include <iostream>
#include <algorithm>
using namespace std;
long long BinarySearch(long long,long long,long long,long long, long long *);
int main()
{
    long long n,m;
    long long max=0;
    long long *arr;
    cin>>n>>m;
    arr=new long long[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(max<arr[i])
            max=arr[i];
    }
    cout<<BinarySearch(n,m,1,max,arr);
}
long long BinarySearch(long long n,long long m,long long first,long long last, long long *arr)
{
    while(last>=first)
    {
        long long output;
        long long hight=0;
        long long mid=(first+last)/2;
        for(int i=0;i<n;i++)
            if((arr[i]-mid)>0)
                hight+=arr[i]-mid;
        if(hight==m)
            output=mid;
        if(hight>=m)
            first=mid+1;
        else
            last=mid-1;
    }
    return last;
}
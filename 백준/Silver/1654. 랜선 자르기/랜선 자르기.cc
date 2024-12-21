#include<iostream>
#include<algorithm>
using namespace std;
long long BinarySearch(int,int,long long,long long, int *);
int main()
{
    int k,n;
    long long max=0;
    int *arr;
    cin>>k>>n;
    arr=new int[k];
    for(int i=0;i<k;i++)
    {
        cin>>arr[i];
        if(max<arr[i])
            max=arr[i];
    }
    cout<<BinarySearch(k,n,1,max,arr);
    
}
long long BinarySearch(int k,int n,long long first,long long last, int *arr)
{
    while(last>=first)
    {
        int count=0;
        long long mid=(first+last)/2;
        for(int i=0;i<k;i++)
            count+=arr[i]/mid;
        if(count>=n)
            first=mid+1;
        else
            last=mid-1;
    }
    return last;
}
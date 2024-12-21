#include <iostream>
#include <algorithm>

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
        cout<<upper_bound(beforenum, beforenum+beforein,afternum[i])-lower_bound(beforenum, beforenum+beforein,afternum[i])<<" ";
}